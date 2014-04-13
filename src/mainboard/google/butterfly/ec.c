/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2012 The Chromium OS Authors. All rights reserved.
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

#include <arch/acpi.h>
#include <vendorcode/google/chromeos/chromeos.h>
#include <types.h>
#include <console/console.h>
#include <ec/quanta/ene_kb3940q/ec.h>
#include "ec.h"

void butterfly_ec_init(void)
{
	printk(BIOS_DEBUG, "Butterfly EC Init\n");

	/* TODO: MLR */
	/* Finish EC init */

	/* Report EC info */
	/* EC version: 6 bytes */
	printk(BIOS_DEBUG,"  EC version: %c%c%c%c%c%c\n",
		   ec_mem_read(EC_FW_VER0), ec_mem_read(EC_FW_VER1),
		   ec_mem_read(EC_FW_VER2), ec_mem_read(EC_FW_VER3),
		   ec_mem_read(EC_FW_VER4), ec_mem_read(EC_FW_VER5));

	printk(BIOS_DEBUG,"  Battery Type: %c%c%c%c\n",
		   ec_mem_read(EC_BAT_CHEMISTRY0), ec_mem_read(EC_BAT_CHEMISTRY1),
		   ec_mem_read(EC_BAT_CHEMISTRY2), ec_mem_read(EC_BAT_CHEMISTRY3));

	printk(BIOS_DEBUG,"  Battery Device Name: %c%c%c%c%c%c%c\n",
		   ec_mem_read(EC_BAT_DEVICE_NAME0), ec_mem_read(EC_BAT_DEVICE_NAME1),
		   ec_mem_read(EC_BAT_DEVICE_NAME2), ec_mem_read(EC_BAT_DEVICE_NAME3),
		   ec_mem_read(EC_BAT_DEVICE_NAME4), ec_mem_read(EC_BAT_DEVICE_NAME5),
		   ec_mem_read(EC_BAT_DEVICE_NAME6));

	/* US Keyboard */
	ec_mem_write(EC_KBID_REG, EC_KBD_EN);

}
