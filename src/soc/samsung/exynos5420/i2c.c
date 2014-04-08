/*
 * This file is part of the coreboot project.
 *
 * (C) Copyright 2002
 * David Mueller, ELSOFT AG, d.mueller@elsoft.ch
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <arch/io.h>
#include <assert.h>
#include <console/console.h>
#include <delay.h>
#include <device/i2c.h>
#include <timer.h>
#include <stddef.h>
#include "clk.h"
#include "i2c.h"
#include "periph.h"
#include "pinmux.h"

struct __attribute__ ((packed)) i2c_regs
{
	uint8_t con;
	uint8_t _1[3];
	uint8_t stat;
	uint8_t _2[3];
	uint8_t add;
	uint8_t _3[3];
	uint8_t ds;
	uint8_t _4[3];
	uint8_t lc;
	uint8_t _5[3];
};

struct __attribute__ ((packed)) hsi2c_regs
{
	uint32_t usi_ctl;
	uint32_t usi_fifo_ctl;
	uint32_t usi_trailing_ctl;
	uint32_t usi_clk_ctl;
	uint32_t usi_clk_slot;
	uint32_t spi_ctl;
	uint32_t uart_ctl;
	uint32_t res1;
	uint32_t usi_int_en;
	uint32_t usi_int_stat;
	uint32_t modem_stat;
	uint32_t error_stat;
	uint32_t usi_fifo_stat;
	uint32_t usi_txdata;
	uint32_t usi_rxdata;
	uint32_t res2;
	uint32_t i2c_conf;
	uint32_t i2c_auto_conf;
	uint32_t i2c_timeout;
	uint32_t i2c_manual_cmd;
	uint32_t i2c_trans_status;
	uint32_t i2c_timing_hs1;
	uint32_t i2c_timing_hs2;
	uint32_t i2c_timing_hs3;
	uint32_t i2c_timing_fs1;
	uint32_t i2c_timing_fs2;
	uint32_t i2c_timing_fs3;
	uint32_t i2c_timing_sla;
	uint32_t i2c_addr;
};
check_member(hsi2c_regs, i2c_addr, 0x70);

struct i2c_bus
{
	int bus_num;
	struct i2c_regs *regs;
	enum periph_id periph_id;
	struct hsi2c_regs *hsregs;
	int is_highspeed;	/* High speed type, rather than I2C */
	int id;
	unsigned clk_cycle;
	unsigned clk_div;
};


static struct i2c_bus i2c_busses[] = {
	{
		.bus_num = 0,
		.regs = (void *)0x12c60000,
		.periph_id = PERIPH_ID_I2C0,
	},
	{
		.bus_num = 1,
		.regs = (void *)0x12c70000,
		.periph_id = PERIPH_ID_I2C1,
	},
	{
		.bus_num = 2,
		.regs = (void *)0x12c80000,
		.periph_id = PERIPH_ID_I2C2,
	},
	{
		.bus_num = 3,
		.regs = (void *)0x12c90000,
		.periph_id = PERIPH_ID_I2C3,
	},
	/* I2C4-I2C10 are part of the USI block */
	{
		.bus_num = 4,
		.hsregs = (void *)0x12ca0000,
		.periph_id = PERIPH_ID_I2C4,
		.is_highspeed = 1,
	},
	{
		.bus_num = 5,
		.hsregs = (void *)0x12cb0000,
		.periph_id = PERIPH_ID_I2C5,
		.is_highspeed = 1,
	},
	{
		.bus_num = 6,
		.hsregs = (void *)0x12cc0000,
		.periph_id = PERIPH_ID_I2C6,
		.is_highspeed = 1,
	},
	{
		.bus_num = 7,
		.hsregs = (void *)0x12cd0000,
		.periph_id = PERIPH_ID_I2C7,
		.is_highspeed = 1,
	},
	{
		.bus_num = 8,
		.hsregs = (void *)0x12e00000,
		.periph_id = PERIPH_ID_I2C8,
		.is_highspeed = 1,
	},
	{
		.bus_num = 9,
		.hsregs = (void *)0x12e10000,
		.periph_id = PERIPH_ID_I2C9,
		.is_highspeed = 1,
	},
	{
		.bus_num = 10,
		.hsregs = (void *)0x12e20000,
		.periph_id = PERIPH_ID_I2C10,
		.is_highspeed = 1,
	},
};

// I2C_CTL
enum {
	Hsi2cFuncModeI2c = 1 << 0,
	Hsi2cMaster = 1 << 3,
	Hsi2cRxchon = 1 << 6,
	Hsi2cTxchon = 1 << 7,
	Hsi2cSwRst = 1 << 31
};

// I2C_FIFO_STAT
enum {
	Hsi2cTxFifoLevel = 0x7f << 0,
	Hsi2cTxFifoFull = 1 << 7,
	Hsi2cTxFifoEmpty = 1 << 8,
	Hsi2cRxFifoLevel = 0x7f << 16,
	Hsi2cRxFifoFull = 1 << 23,
	Hsi2cRxFifoEmpty = 1 << 24
};

// I2C_FIFO_CTL
enum {
	Hsi2cRxfifoEn = 1 << 0,
	Hsi2cTxfifoEn = 1 << 1,
	Hsi2cTxfifoTriggerLevel = 0x20 << 16,
	Hsi2cRxfifoTriggerLevel = 0x20 << 4
};

// I2C_TRAILING_CTL
enum {
	Hsi2cTrailingCount = 0xff
};

// I2C_INT_EN
enum {
	Hsi2cIntTxAlmostemptyEn = 1 << 0,
	Hsi2cIntRxAlmostfullEn = 1 << 1,
	Hsi2cIntTrailingEn = 1 << 6,
	Hsi2cIntI2cEn = 1 << 9
};

// I2C_CONF
enum {
	Hsi2cAutoMode = 1 << 31,
	Hsi2c10bitAddrMode = 1 << 30,
	Hsi2cHsMode = 1 << 29
};

// I2C_AUTO_CONF
enum {
	Hsi2cReadWrite = 1 << 16,
	Hsi2cStopAfterTrans = 1 << 17,
	Hsi2cMasterRun = 1 << 31
};

// I2C_TIMEOUT
enum {
	Hsi2cTimeoutEn = 1 << 31
};

// I2C_TRANS_STATUS
enum {
	Hsi2cMasterBusy = 1 << 17,
	Hsi2cSlaveBusy = 1 << 16,
	Hsi2cTimeoutAuto = 1 << 4,
	Hsi2cNoDev = 1 << 3,
	Hsi2cNoDevAck = 1 << 2,
	Hsi2cTransAbort = 1 << 1,
	Hsi2cTransDone = 1 << 0
};

#define HSI2C_SLV_ADDR_MAS(x)		((x & 0x3ff) << 10)

enum {
	Hsi2cTimeout = 100
};

enum {
	I2cConIntPending = 0x1 << 4,
	I2cConIntEn = 0x1 << 5,
	I2cConAckGen = 0x1 << 7
};

enum {
	I2cStatAck = 0x1 << 0,
	I2cStatAddrZero = 0x1 << 1,
	I2cStatAddrSlave = 0x1 << 2,
	I2cStatArb = 0x1 << 3,
	I2cStatEnable = 0x1 << 4,
	I2cStatStartStop = 0x1 << 5,
	I2cStatBusy = 0x1 << 5,

	I2cStatModeMask = 0x3 << 6,
	I2cStatSlaveRecv = 0x0 << 6,
	I2cStatSlaveXmit = 0x1 << 6,
	I2cStatMasterRecv = 0x2 << 6,
	I2cStatMasterXmit = 0x3 << 6
};




static int hsi2c_get_clk_details(struct i2c_bus *i2c, int *div, int *cycle,
				 unsigned op_clk)
{
	struct hsi2c_regs *regs = i2c->hsregs;
	unsigned long clkin = clock_get_periph_rate(i2c->periph_id);

	/*
	 * FPCLK / FI2C =
	 * (CLK_DIV + 1) * (TSCLK_L + TSCLK_H + 2) + 8 + 2 * FLT_CYCLE
	 * temp0 = (CLK_DIV + 1) * (TSCLK_L + TSCLK_H + 2)
	 * temp1 = (TSCLK_L + TSCLK_H + 2)
	 */
	uint32_t flt_cycle = (readl(&regs->i2c_conf) >> 16) & 0x7;
	int temp = (clkin / op_clk) - 8 - 2 * flt_cycle;

	// CLK_DIV max is 256.
	int i;
	for (i = 0; i < 256; i++) {
		int period = temp / (i + 1) - 2;
		if (period < 512 && period >= 2) {
			*cycle = period;
			*div = i;
			return 0;
		}
	}
	printk(BIOS_ERR, "%s: Failed to find timing parameters.\n", __func__);
	return -1;
}

static void hsi2c_ch_init(struct i2c_bus *i2c, unsigned int frequency)
{
	struct hsi2c_regs *regs = i2c->hsregs;

	int div, cycle;
	if (hsi2c_get_clk_details(i2c, &div, &cycle, frequency))
		return;

	uint32_t sr_release;
	sr_release = cycle;

	uint32_t scl_l, scl_h, start_su, start_hd, stop_su;
	scl_l = scl_h = start_su = start_hd = stop_su = cycle / 2;

	uint32_t data_su, data_hd;
	data_su = data_hd = cycle / 4;

	uint32_t timing_fs1 = start_su << 24 | start_hd << 16 | stop_su << 8;
	uint32_t timing_fs2 = data_su << 24 | scl_l << 8 | scl_h << 0;
	uint32_t timing_fs3 = div << 16 | sr_release << 0;
	uint32_t timing_sla = data_hd << 0;

	// Currently operating in fast speed mode.
	writel(timing_fs1, &regs->i2c_timing_fs1);
	writel(timing_fs2, &regs->i2c_timing_fs2);
	writel(timing_fs3, &regs->i2c_timing_fs3);
	writel(timing_sla, &regs->i2c_timing_sla);

	// Clear to enable timeout.
	writel(readl(&regs->i2c_timeout) & ~Hsi2cTimeoutEn,
	       &regs->i2c_timeout);

	writel(Hsi2cTrailingCount, &regs->usi_trailing_ctl);
	writel(Hsi2cRxfifoEn | Hsi2cTxfifoEn, &regs->usi_fifo_ctl);
	writel(readl(&regs->i2c_conf) | Hsi2cAutoMode, &regs->i2c_conf);
}

static void hsi2c_reset(struct i2c_bus *i2c)
{
	struct hsi2c_regs *regs = i2c->hsregs;

	// Set and clear the bit for reset.
	writel(readl(&regs->usi_ctl) | Hsi2cSwRst, &regs->usi_ctl);
	writel(readl(&regs->usi_ctl) & ~Hsi2cSwRst, &regs->usi_ctl);

	/* FIXME: This just assumes 100KHz as a default bus freq */
	hsi2c_ch_init(i2c, 100000);
}

static void i2c_ch_init(struct i2c_bus *i2c, int speed)
{
	struct i2c_regs *regs = i2c->regs;

	unsigned long freq, pres = 16, div;
	unsigned long val;

	freq = clock_get_periph_rate(i2c->periph_id);
	// Calculate prescaler and divisor values.
	if ((freq / pres / (16 + 1)) > speed)
		/* set prescaler to 512 */
		pres = 512;

	div = 0;

	while ((freq / pres / (div + 1)) > speed)
		div++;

	// Set prescaler, divisor according to freq, also set ACKGEN, IRQ.
	val = (div & 0x0f) | 0xa0 | ((pres == 512) ? 0x40 : 0);
	writel(val, &regs->con);

	// Init to SLAVE RECEIVE mode and clear I2CADDn.
	writel(0, &regs->stat);
	writel(0, &regs->add);
	// program Master Transmit (and implicit STOP).
	writel(I2cStatMasterXmit | I2cStatEnable, &regs->stat);
}

void i2c_init(unsigned bus, int speed, int slaveadd)
{
	struct i2c_bus *i2c = &i2c_busses[bus];

	if (i2c->is_highspeed) {
		hsi2c_reset(i2c);
		hsi2c_ch_init(i2c, speed);
	} else {
		i2c_ch_init(i2c, speed);
	}
}

/*
 * Check whether the transfer is complete.
 * Return values:
 * 0  - transfer not done
 * 1  - transfer finished successfully
 * -1 - transfer failed
 */
static int hsi2c_check_transfer(struct hsi2c_regs *regs)
{
	uint32_t status = read32(&regs->i2c_trans_status);
	if (status & (Hsi2cTransAbort | Hsi2cNoDevAck |
		      Hsi2cNoDev | Hsi2cTimeoutAuto)) {
		if (status & Hsi2cTransAbort)
			printk(BIOS_ERR,
			       "%s: Transaction aborted.\n", __func__);
		if (status & Hsi2cNoDevAck)
			printk(BIOS_ERR,
			       "%s: No ack from device.\n", __func__);
		if (status & Hsi2cNoDev)
			printk(BIOS_ERR,
			       "%s: No response from device.\n", __func__);
		if (status & Hsi2cTimeoutAuto)
			printk(BIOS_ERR,
			       "%s: Transaction time out.\n", __func__);
		return -1;
	}
	return !(status & Hsi2cMasterBusy);
}

/*
 * Wait for the transfer to finish.
 * Return values:
 * 0  - transfer not done
 * 1  - transfer finished successfully
 * -1 - transfer failed
 */
static int hsi2c_wait_for_transfer(struct hsi2c_regs *i2c)
{
	struct mono_time current, end;

	timer_monotonic_get(&current);
	end = current;
	mono_time_add_usecs(&end, Hsi2cTimeout * 1000);
	while (mono_time_before(&current, &end)) {
		int ret = hsi2c_check_transfer(i2c);
		if (ret)
			return ret;
		timer_monotonic_get(&current);
	}
	return 0;
}

static int hsi2c_senddata(struct hsi2c_regs *regs, const uint8_t *data, int len)
{
	while (!hsi2c_check_transfer(regs) && len) {
		if (!(read32(&regs->usi_fifo_stat) & Hsi2cTxFifoFull)) {
			write32(*data++, &regs->usi_txdata);
			len--;
		}
	}
	return len ? -1 : 0;
}

static int hsi2c_recvdata(struct hsi2c_regs *regs, uint8_t *data, int len)
{
	while (!hsi2c_check_transfer(regs) && len) {
		if (!(read32(&regs->usi_fifo_stat) & Hsi2cRxFifoEmpty)) {
			*data++ = read32(&regs->usi_rxdata);
			len--;
		}
	}
	return len ? -1 : 0;
}

static int hsi2c_segment(struct i2c_seg *seg, struct hsi2c_regs *regs, int stop)
{
	const uint32_t usi_ctl = Hsi2cFuncModeI2c | Hsi2cMaster;

	write32(HSI2C_SLV_ADDR_MAS(seg->chip), &regs->i2c_addr);

	/*
	 * We really only want to stop after this transaction (I think) if the
	 * "stop" parameter is true. I'm assuming that's supposed to make the
	 * controller issue a repeated start, but the documentation isn't very
	 * clear. We may need to switch to manual mode to really get the
	 * behavior we want.
	 */
	uint32_t autoconf =
		seg->len | Hsi2cMasterRun | Hsi2cStopAfterTrans;

	if (seg->read) {
		write32(usi_ctl | Hsi2cRxchon, &regs->usi_ctl);
		write32(autoconf | Hsi2cReadWrite, &regs->i2c_auto_conf);

		if (hsi2c_recvdata(regs, seg->buf, seg->len))
			return -1;
	} else {
		write32(usi_ctl | Hsi2cTxchon, &regs->usi_ctl);
		write32(autoconf, &regs->i2c_auto_conf);

		if (hsi2c_senddata(regs, seg->buf, seg->len))
			return -1;
	}

	if (hsi2c_wait_for_transfer(regs) != 1)
		return -1;

	writel(Hsi2cFuncModeI2c, &regs->usi_ctl);
	return 0;
}

static int hsi2c_transfer(struct i2c_bus *i2c, struct i2c_seg *segments,
			  int count)
{
	struct hsi2c_regs *regs = i2c->hsregs;
	if (hsi2c_wait_for_transfer(regs) != 1) {
		hsi2c_reset(i2c);
		return -1;
	}

	int i;
	for (i = 0; i < count; i++) {
		if (hsi2c_segment(&segments[i], regs, i == count - 1)) {
			hsi2c_reset(i2c);
			return -1;
		}
	}

	return 0;
}




static int i2c_int_pending(struct i2c_regs *regs)
{
	return readb(&regs->con) & I2cConIntPending;
}

static void i2c_clear_int(struct i2c_regs *regs)
{
	writeb(readb(&regs->con) & ~I2cConIntPending, &regs->con);
}

static void i2c_ack_enable(struct i2c_regs *regs)
{
	writeb(readb(&regs->con) | I2cConAckGen, &regs->con);
}

static void i2c_ack_disable(struct i2c_regs *regs)
{
	writeb(readb(&regs->con) & ~I2cConAckGen, &regs->con);
}

static int i2c_got_ack(struct i2c_regs *regs)
{
	return !(readb(&regs->stat) & I2cStatAck);
}

static int i2c_wait_for_idle(struct i2c_regs *regs)
{
	int timeout = 1000 * 100; // 1s.
	while (timeout--) {
		if (!(readb(&regs->stat) & I2cStatBusy))
			return 0;
		udelay(10);
	}
	printk(BIOS_ERR, "I2C timeout waiting for idle.\n");
	return 1;
}

static int i2c_wait_for_int(struct i2c_regs *regs)
{
	int timeout = 1000 * 100; // 1s.
	while (timeout--) {
		if (i2c_int_pending(regs))
			return 0;
		udelay(10);
	}
	printk(BIOS_ERR, "I2C timeout waiting for I2C interrupt.\n");
	return 1;
}




static int i2c_send_stop(struct i2c_regs *regs)
{
	uint8_t mode = readb(&regs->stat) & (I2cStatModeMask);
	writeb(mode | I2cStatEnable, &regs->stat);
	i2c_clear_int(regs);
	return i2c_wait_for_idle(regs);
}

static int i2c_send_start(struct i2c_regs *regs, int read, int chip)
{
	writeb(chip << 1, &regs->ds);
	uint8_t mode = read ? I2cStatMasterRecv : I2cStatMasterXmit;
	writeb(mode | I2cStatStartStop | I2cStatEnable, &regs->stat);
	i2c_clear_int(regs);

	if (i2c_wait_for_int(regs))
		return 1;

	if (!i2c_got_ack(regs)) {
		// Nobody home, but they may just be asleep.
		return 1;
	}

	return 0;
}

static int i2c_xmit_buf(struct i2c_regs *regs, uint8_t *data, int len)
{
	ASSERT(len);

	i2c_ack_enable(regs);

	int i;
	for (i = 0; i < len; i++) {
		writeb(data[i], &regs->ds);

		i2c_clear_int(regs);
		if (i2c_wait_for_int(regs))
			return 1;

		if (!i2c_got_ack(regs)) {
			printk(BIOS_INFO, "I2c nacked.\n");
			return 1;
		}
	}

	return 0;
}

static int i2c_recv_buf(struct i2c_regs *regs, uint8_t *data, int len)
{
	ASSERT(len);

	i2c_ack_enable(regs);

	int i;
	for (i = 0; i < len; i++) {
		if (i == len - 1)
			i2c_ack_disable(regs);

		i2c_clear_int(regs);
		if (i2c_wait_for_int(regs))
			return 1;

		data[i] = readb(&regs->ds);
	}

	return 0;
}

int i2c_transfer(unsigned bus, struct i2c_seg *segments, int count)
{
	struct i2c_bus *i2c = &i2c_busses[bus];
	if (i2c->is_highspeed)
		return hsi2c_transfer(i2c, segments, count);

	struct i2c_regs *regs = i2c->regs;
	int res = 0;

	if (!regs || i2c_wait_for_idle(regs))
		return 1;

	writeb(I2cStatMasterXmit | I2cStatEnable, &regs->stat);

	int i;
	for (i = 0; i < count; i++) {
		struct i2c_seg *seg = &segments[i];

		res = i2c_send_start(regs, seg->read, seg->chip);
		if (res)
			break;
		if (seg->read)
			res = i2c_recv_buf(regs, seg->buf, seg->len);
		else
			res = i2c_xmit_buf(regs, seg->buf, seg->len);
		if (res)
			break;
	}

	return i2c_send_stop(regs) || res;
}
