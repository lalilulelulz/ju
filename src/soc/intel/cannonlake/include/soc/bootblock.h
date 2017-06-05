/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2017 Intel Corporation
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _SOC_CANNONLAKE_BOOTBLOCK_H_
#define _SOC_CANNONLAKE_BOOTBLOCK_H_

#include <intelblocks/systemagent.h>

/* Bootblock pre console init programing */
void bootblock_cpu_init(void);
void bootblock_pch_early_init(void);

/* Bootblock post console init programing */
void pch_early_init(void);
void pch_early_iorange_init(void);
void report_platform_info(void);
void set_max_freq(void);

#endif
