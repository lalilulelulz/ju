/*
 * This file is part of the libpayload project.
 *
 * Copyright (C) 2008 Advanced Micro Devices, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/**
 * @mainpage
 *
 * @section intro Introduction
 * libpayload is a small BSD-licensed static library (a lightweight
 * implementation of common and useful functions) intended to be used
 * as a basis for coreboot payloads.
 *
 * @section example Example
 * Here is an example of a very simple payload:
 * @include sample/hello.c
 */

#ifndef _LIBPAYLOAD_H
#define _LIBPAYLOAD_H

#include <libpayload-config.h>
#include <cbgfx.h>
#include <ctype.h>
#include <die.h>
#include <endian.h>
#include <fmap_serialized.h>
#include <ipchksum.h>
#include <kconfig.h>
#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <arch/types.h>
#include <arch/io.h>
#include <arch/virtual.h>
#include <sysinfo.h>
#include <pci.h>
#include <archive.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

static inline u32 div_round_up(u32 n, u32 d) { return (n + d - 1) / d; }

#define LITTLE_ENDIAN	1234
#define BIG_ENDIAN	4321

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define RAND_MAX 0x7fffffff

#define MAX_ARGC_COUNT 32

/*
 * Payload information parameters - these are used to pass information
 * to the entity loading the payload.
 * Usage:   PAYLOAD_INFO(key, value)
 * Example: PAYLOAD_INFO(name, "CoreInfo!")
 */
#define _pstruct(key) __pinfo_ ##key
#define PAYLOAD_INFO(key, value)                                        \
static const char _pstruct(key)[]                                        \
  __attribute__((__used__))                                              \
  __attribute__((section(".note.pinfo"),unused)) = #key "=" value

/**
 * @defgroup nvram NVRAM and RTC functions
 * @{
 */

#define NVRAM_RTC_SECONDS        0      /**< RTC Seconds offset in CMOS */
#define NVRAM_RTC_MINUTES        2      /**< RTC Minutes offset in CMOS */
#define NVRAM_RTC_HOURS          4      /**< RTC Hours offset in CMOS */
#define NVRAM_RTC_DAY            7      /**< RTC Days offset in CMOS */
#define NVRAM_RTC_MONTH          8      /**< RTC Month offset in CMOS */
#define NVRAM_RTC_YEAR           9      /**< RTC Year offset in CMOS */
#define NVRAM_RTC_FREQ_SELECT    10     /**< RTC Update Status Register */
#define  NVRAM_RTC_UIP           0x80

/** Broken down time structure */
struct tm {
	int tm_sec;   /**< Number of seconds after the minute */
	int tm_min;   /**< Number of minutes after the hour */
	int tm_hour;  /**< Number of hours past midnight */
	int tm_mday;  /**< The day of the month */
	int tm_mon;   /**< The month of the year */
	int tm_year;  /**< The number of years since 1900 */
	int tm_wday;  /**< The day of the week */
	int tm_yday;  /**< The number of days since January 1 */
	int tm_isdst; /**< A flag indicating daylight savings time */
};

u8 nvram_read(u8 addr);
void nvram_write(u8 val, u8 addr);
int nvram_updating(void);
void rtc_read_clock(struct tm *tm);
/** @} */

/**
 * @defgroup storage driver functions
 * @{
 */
void storage_initialize(void);
/** @} */

/**
 * @defgroup usb USB functions
 * @{
 */
int usb_initialize(void);
int usb_exit (void);
int usbhid_havechar(void);
int usbhid_getchar(void);
/** @} */

/**
 * @defgroup input Device functions
 * @{ @}
 */

extern void (*reset_handler)(void);
int add_reset_handler(void (*new_handler)(void));

/**
 * @defgroup keyboard Keyboard functions
 * @ingroup input
 * @{
 */
void keyboard_init(void);
void keyboard_disconnect(void);
int keyboard_havechar(void);
unsigned char keyboard_get_scancode(void);
int keyboard_getchar(void);
int keyboard_set_layout(char *country);
/** @} */

/**
 * @defgroup mouse Mouse cursor functions
 * @ingroup input
 * @{
 */
void mouse_cursor_poll(void);
void mouse_cursor_get_rel(int *x, int *y, int *z);
u32 mouse_cursor_get_buttons(void);
void mouse_cursor_set_speed(u32 val);
u32 mouse_cursor_get_speed(void);
void mouse_cursor_set_acceleration(u8 val);
u8 mouse_cursor_get_acceleration(void);
/** @} */

/**
 * @defgroup serial Serial functions
 * @ingroup input
 * @{
 */
void serial_init(void);
void serial_console_init(void);
void serial_putchar(unsigned int c);
int serial_havechar(void);
int serial_getchar(void);
void serial_clear(void);
void serial_start_bold(void);
void serial_end_bold(void);
void serial_start_reverse(void);
void serial_end_reverse(void);
void serial_start_altcharset(void);
void serial_end_altcharset(void);
void serial_set_color(short fg, short bg);
void serial_cursor_enable(int state);
void serial_set_cursor(int y, int x);
/** @} */

/**
 * @defgroup speaker Speaker functions
 * @ingroup input
 * @{
 */
void speaker_enable(u16 freq);
void speaker_disable(void);
void speaker_tone(u16 freq, unsigned int duration);
/** @} */

/**
 * @defgroup video Video functions
 * @ingroup input
 * @{
 */
int video_init(void);
int video_console_init(void);
void video_get_rows_cols(unsigned int *rows, unsigned int *cols);
void video_console_putchar(unsigned int ch);
void video_console_putc(u8 row, u8 col, unsigned int ch);
void video_console_clear(void);
void video_console_cursor_enable(int state);
void video_console_get_cursor(unsigned int *x, unsigned int *y, unsigned int *en);
void video_console_set_cursor(unsigned int cursorx, unsigned int cursory);
/*
 * print characters on video console with colors. note that there is a size
 * restriction for the internal buffer. so, output string can be truncated.
 */
enum video_printf_align {
	VIDEO_PRINTF_ALIGN_KEEP = 0,
	VIDEO_PRINTF_ALIGN_LEFT,
	VIDEO_PRINTF_ALIGN_CENTER,
	VIDEO_PRINTF_ALIGN_RIGHT,
};
void video_printf(int foreground, int background, enum video_printf_align align,
		  const char *fmt, ...);
/** @} */

/**
 * @defgroup cbmem_console CBMEM memory console.
 * @ingroup input
 * @{
 */
void cbmem_console_init(void);
void cbmem_console_write(const void *buffer, size_t count);
/** @} */

/* drivers/option.c */
struct nvram_accessor {
	u8 (*read)(u8 reg);
	void (*write)(u8 val, u8 reg);
};

extern u8 *mem_accessor_base;
extern struct nvram_accessor *use_nvram, *use_mem;

struct cb_cmos_option_table *get_system_option_table(void);
int options_checksum_valid(const struct nvram_accessor *nvram);
void fix_options_checksum_with(const struct nvram_accessor *nvram);
void fix_options_checksum(void);

struct cb_cmos_entries *first_cmos_entry(struct cb_cmos_option_table *option_table);
struct cb_cmos_entries *next_cmos_entry(struct cb_cmos_entries *cur);

struct cb_cmos_enums *first_cmos_enum(struct cb_cmos_option_table *option_table);
struct cb_cmos_enums *next_cmos_enum(struct cb_cmos_enums *cmos_enum);
struct cb_cmos_enums *first_cmos_enum_of_id(struct cb_cmos_option_table *option_table, int id);
struct cb_cmos_enums *next_cmos_enum_of_id(struct cb_cmos_enums *cmos_enum, int id);

int get_option_with(const struct nvram_accessor *nvram, struct cb_cmos_option_table *option_table, void *dest, const char *name);
int get_option_from(struct cb_cmos_option_table *option_table, void *dest, const char *name);
int get_option(void *dest, const char *name);
int set_option_with(const struct nvram_accessor *nvram, struct cb_cmos_option_table *option_table, const void *value, const char *name);
int set_option(const void *value, const char *name);
int get_option_as_string(const struct nvram_accessor *nvram, struct cb_cmos_option_table *option_table, char **dest, const char *name);
int set_option_from_string(const struct nvram_accessor *nvram, struct cb_cmos_option_table *option_table, const char *value, const char *name);

/**
 * @defgroup console Console functions
 * @{
 */
typedef enum {
	CONSOLE_INPUT_TYPE_UNKNOWN = 0,
	CONSOLE_INPUT_TYPE_USB,
} console_input_type;

void console_init(void);
void console_write(const void *buffer, size_t count);
int putchar(unsigned int c);
int puts(const char *s);
int havekey(void);
int getchar(void);
int getchar_timeout(int *ms);
console_input_type last_key_input_type(void);

extern int last_putchar;

struct console_input_driver;
struct console_input_driver {
	struct console_input_driver *next;
	int (*havekey) (void);
	int (*getchar) (void);
	console_input_type input_type;
};

struct console_output_driver;
struct console_output_driver {
	struct console_output_driver *next;
	void (*putchar) (unsigned int);
	void (*write) (const void *, size_t);
};

void console_add_output_driver(struct console_output_driver *out);
void console_add_input_driver(struct console_input_driver *in);
int console_remove_output_driver(void *function);

#define havechar havekey
/** @} */

/**
 * @defgroup mouse_cursor Mouse cursor functions
 * @{
 */
typedef enum {
	CURSOR_INPUT_TYPE_UNKNOWN = 0,
	CURSOR_INPUT_TYPE_USB,
	CURSOR_INPUT_TYPE_PS2,
} cursor_input_type;

void mouse_cursor_init(void);

struct mouse_cursor_input_driver;
struct mouse_cursor_input_driver {
	struct mouse_cursor_input_driver *next;
	/* X,Y,Z axis and buttons */
	void (*get_state)(int *, int *, int *, u32 *);
	cursor_input_type input_type;
};

void mouse_cursor_add_input_driver(struct mouse_cursor_input_driver *in);

/** @} */

/**
 * @defgroup exec Execution functions
 * @{
 */
int exec(long addr, int argc, char **argv);
/** @} */

/**
 * @defgroup misc Misc functions
 * @{
 */
int bcd2dec(int b);
int dec2bcd(int d);
int abs(int j);
long int labs(long int j);
long long int llabs(long long int j);
u8 bin2hex(u8 b);
u8 hex2bin(u8 h);
void hexdump(const void *memory, size_t length);
void fatal(const char *msg) __attribute__ ((noreturn));

/* Count Leading Zeroes: clz(0) == 32, clz(0xf) == 28, clz(1 << 31) == 0 */
static inline int clz(u32 x) { return x ? __builtin_clz(x) : sizeof(x) * 8; }
/* Integer binary logarithm (rounding down): log2(0) == -1, log2(5) == 2 */
static inline int log2(u32 x) { return sizeof(x) * 8 - clz(x) - 1; }
/* Find First Set: __ffs(0xf) == 0, __ffs(0) == -1, __ffs(1 << 31) == 31 */
static inline int __ffs(u32 x) { return log2(x & (u32)(-(s32)x)); }
/** @} */


/**
 * @defgroup hash Hashing functions
 * @{
 */
#define SHA1_BLOCK_LENGTH	64
#define SHA1_DIGEST_LENGTH	20
typedef struct {
	u32 state[5];
	u64 count;
	u8 buffer[SHA1_BLOCK_LENGTH];
} SHA1_CTX;
void SHA1Init(SHA1_CTX *context);
void SHA1Transform(u32 state[5], const u8 buffer[SHA1_BLOCK_LENGTH]);
void SHA1Update(SHA1_CTX *context, const u8 *data, size_t len);
void SHA1Pad(SHA1_CTX *context);
void SHA1Final(u8 digest[SHA1_DIGEST_LENGTH], SHA1_CTX *context);
u8 *sha1(const u8 *data, size_t len, u8 *buf);
/** @} */

/**
 * @defgroup info System information functions
 * This module contains functions that return information about the system
 * @{
 */

int sysinfo_have_multiboot(unsigned long *addr);
/** @} */

/**
 * @defgroup arch Architecture specific functions
 * This module contains global architecture specific functions.
 * All architectures are expected to define these functions.
 * @{
 */
int get_coreboot_info(struct sysinfo_t *info);
int get_multiboot_info(struct sysinfo_t *info);
void *get_cb_header_ptr(void);

int lib_get_sysinfo(void);
void lib_sysinfo_get_memranges(struct memrange **ranges,
			       uint64_t *nranges);

/* Timer functions. */
/* Defined by each architecture. */
unsigned int get_cpu_speed(void);
uint64_t timer_hz(void);
uint64_t timer_raw_value(void);
uint64_t timer_us(uint64_t base);
/* Generic. */
void ndelay(unsigned int n);
void udelay(unsigned int n);
void mdelay(unsigned int n);
void delay(unsigned int n);

/**
 * @defgroup readline Readline functions
 * This interface provides a simple implementation of the standard readline()
 * and getline() functions. They read a line of input from the console.
 * @{
 */
char *readline(const char *prompt);
int getline(char *buffer, int len);
/** @} */

/* Defined in arch/${ARCH}/selfboot.c */
void selfboot(void *entry);

/* Enter remote GDB mode. Will initialize connection if not already up. */
void gdb_enter(void);
/* Disconnect existing GDB connection if one exists. */
void gdb_exit(s8 exit_status);

/* look for area "name" in "fmap", setting offset and size to describe it.
   Returns 0 on success, < 0 on error. */
int fmap_region_by_name(const uint32_t fmap_offset, const char * const name,
			uint32_t * const offset, uint32_t * const size);
#endif
