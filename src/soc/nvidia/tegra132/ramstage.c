/*
 * This file is part of the coreboot project.
 *
 * Copyright 2014 Google Inc.
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
 * Foundation, Inc.
 */

#include <arch/stages.h>
#include <soc/addressmap.h>
#include <soc/clock.h>
#include <soc/mc.h>
#include <soc/mmu_operations.h>

static void lock_down_vpr(void)
{
	struct tegra_mc_regs *regs = (void *)(uintptr_t)TEGRA_MC_BASE;

	write32(&regs->video_protect_bom, 0);
	write32(&regs->video_protect_size_mb, 0);
	write32(&regs->video_protect_reg_ctrl, 1);
}

void arm64_soc_init(void)
{
	trustzone_region_init();

	tegra132_mmu_init();

	clock_cpu0_config();

	clock_init_arm_generic_timer();

	/* Lock down VPR */
	lock_down_vpr();
}
