/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2017 Intel Corporation.
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

#ifndef _SOC_APOLLOLAKE_PNPCONFIG_H_
#define _SOC_APOLLOLAKE_PNPCONFIG_H_

#include <soc/pcr_ids.h>

#define MAKE_MASK_INCLUSIVE(msb)	MAKE_MASK(msb+1)

#define MAKE_MASK(msb)			(uint32_t)((1ULL << (msb)) - 1)

#define MASK_VAL(msb, lsb, val) \
	~(MAKE_MASK_INCLUSIVE(msb) & ~MAKE_MASK(lsb)), (val) << (lsb)

struct pnpconfig {
	int		msgport;
	uint32_t	msgregaddr;
	uint32_t	mask;
	uint32_t	value;
};

#define AUNIT_VALUEFORPERF_MSG_VALUES_PLATFORM_DEFAULT \
	/* A_CR_CRDARB_GCNT_DEV_P_0_MCHBAR.CHID0 */ \
	{ PID_AUNIT, 0x6430, MASK_VAL(7, 0, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_P_0_MCHBAR.CHID1 */ \
	{ PID_AUNIT, 0x6430, MASK_VAL(15, 8, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_P_0_MCHBAR.CHID2 */ \
	{ PID_AUNIT, 0x6430, MASK_VAL(23, 16, 0x0) }, \
	/* A_CR_CRDARB_GCNT_DEV_P_0_MCHBAR.CHID3 */ \
	{ PID_AUNIT, 0x6430, MASK_VAL(31, 24, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_P_1_MCHBAR.CHID4 */ \
	{ PID_AUNIT, 0x6434, MASK_VAL(7, 0, 0x0) }, \
	/* A_CR_CRDARB_GCNT_DEV_P_1_MCHBAR.CHID5 */ \
	{ PID_AUNIT, 0x6434, MASK_VAL(15, 8, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_P_1_MCHBAR.CHID6 */ \
	{ PID_AUNIT, 0x6434, MASK_VAL(23, 16, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_P_1_MCHBAR.CHID7 */ \
	{ PID_AUNIT, 0x6434, MASK_VAL(31, 24, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_0_MCHBAR.CHID0 */ \
	{ PID_AUNIT, 0x6438, MASK_VAL(7, 0, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_0_MCHBAR.CHID1 */ \
	{ PID_AUNIT, 0x6438, MASK_VAL(15, 8, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_0_MCHBAR.CHID2 */ \
	{ PID_AUNIT, 0x6438, MASK_VAL(23, 16, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_0_MCHBAR.CHID3 */ \
	{ PID_AUNIT, 0x6438, MASK_VAL(31, 24, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_1_MCHBAR.CHID4 */ \
	{ PID_AUNIT, 0x643c, MASK_VAL(7, 0, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_1_MCHBAR.CHID5 */ \
	{ PID_AUNIT, 0x643c, MASK_VAL(15, 8, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_1_MCHBAR.CHID6 */ \
	{ PID_AUNIT, 0x643c, MASK_VAL(23, 16, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_1_MCHBAR.CHID7 */ \
	{ PID_AUNIT, 0x643c, MASK_VAL(31, 24, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_C_0_MCHBAR.CHID0 */ \
	{ PID_AUNIT, 0x6440, MASK_VAL(7, 0, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_C_0_MCHBAR.CHID1 */ \
	{ PID_AUNIT, 0x6440, MASK_VAL(15, 8, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_C_0_MCHBAR.CHID2 */ \
	{ PID_AUNIT, 0x6440, MASK_VAL(23, 16, 0x0) }, \
	/* A_CR_CRDARB_GCNT_DEV_C_0_MCHBAR.CHID3 */ \
	{ PID_AUNIT, 0x6440, MASK_VAL(31, 24, 0x0) }, \
	/* A_CR_CRDARB_GCNT_CLS_MCHBAR.P */ \
	{ PID_AUNIT, 0x6444, MASK_VAL(7, 0, 0x1) }, \
	/* A_CR_CRDARB_GCNT_CLS_MCHBAR.NP */ \
	{ PID_AUNIT, 0x6444, MASK_VAL(15, 8, 0x1) }, \
	/* A_CR_CRDARB_GCNT_CLS_MCHBAR.C */ \
	{ PID_AUNIT, 0x6444, MASK_VAL(23, 16, 0x1) }, \
	/* A_CR_GZLQ_LIMIT_CH0_3_MCHBAR.CHID0 */ \
	{ PID_AUNIT, 0x6448, MASK_VAL(7, 0, 0x8) }, \
	/* A_CR_GZLQ_LIMIT_CH0_3_MCHBAR.CHID1 */ \
	{ PID_AUNIT, 0x6448, MASK_VAL(15, 8, 0xff) }, \
	/* A_CR_GZLQ_LIMIT_CH0_3_MCHBAR.CHID2 */ \
	{ PID_AUNIT, 0x6448, MASK_VAL(23, 16, 0xff) }, \
	/* A_CR_GZLQ_LIMIT_CH0_3_MCHBAR.CHID3 */ \
	{ PID_AUNIT, 0x6448, MASK_VAL(31, 24, 0xff) }, \
	/* A_CR_GZLQ_LIMIT_CH4_7_MCHBAR.CHID4 */ \
	{ PID_AUNIT, 0x644c, MASK_VAL(7, 0, 0xff) }, \
	/* A_CR_GZLQ_LIMIT_CH4_7_MCHBAR.CHID5 */ \
	{ PID_AUNIT, 0x644c, MASK_VAL(15, 8, 0xff) }, \
	/* A_CR_GZLQ_LIMIT_CH4_7_MCHBAR.CHID6 */ \
	{ PID_AUNIT, 0x644c, MASK_VAL(23, 16, 0xff) }, \
	/* A_CR_GZLQ_LIMIT_CH4_7_MCHBAR.CHID7 */ \
	{ PID_AUNIT, 0x644c, MASK_VAL(31, 24, 0xff) }, \
	/* A_CR_SLICE_CHANNEL_HASH_0_0_0_MCHBAR.SLICE_1_DISABLED */ \
	{ PID_AUNIT, 0x6450, MASK_VAL(0, 0, 0x0) }, \
	/* A_CR_SLICE_CHANNEL_HASH_0_0_0_MCHBAR.HVM_MODE */ \
	{ PID_AUNIT, 0x6450, MASK_VAL(1, 1, 0x0) }, \
	/* A_CR_SLICE_CHANNEL_HASH_0_0_0_MCHBAR.INTERLEAVE_MODE */ \
	{ PID_AUNIT, 0x6450, MASK_VAL(3, 2, 0x2) }, \
	/* A_CR_SLICE_CHANNEL_HASH_0_0_0_MCHBAR.SLICE_HASH_MASK */ \
	{ PID_AUNIT, 0x6450, MASK_VAL(19, 6, 0x9) }, \
	/* A_CR_SLICE_CHANNEL_HASH_0_0_0_MCHBAR.CH_HASH_MASK */ \
	{ PID_AUNIT, 0x6454, MASK_VAL(19, 6, 0x36) }, \
	/* A_CR_CHAP_SLCT1_MCHBAR.CHID_X_CNT_UPTXN */ \
	{ PID_AUNIT, 0x6484, MASK_VAL(7, 0, 0xff) }, \
	/* A_CR_CHAP_SLCT1_MCHBAR.CHID_Y_CNT_UPTXN */ \
	{ PID_AUNIT, 0x6484, MASK_VAL(23, 16, 0xff) }

#define AUNIT_VALUEFORPOWER_MSG_VALUES_PLATFORM_DEFAULT \
	/* A_CR_CRDARB_GCNT_DEV_P_0_MCHBAR.CHID0 */ \
	{ PID_AUNIT, 0x6430, MASK_VAL(7, 0, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_P_0_MCHBAR.CHID1 */ \
	{ PID_AUNIT, 0x6430, MASK_VAL(15, 8, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_P_0_MCHBAR.CHID2 */ \
	{ PID_AUNIT, 0x6430, MASK_VAL(23, 16, 0x0) }, \
	/* A_CR_CRDARB_GCNT_DEV_P_0_MCHBAR.CHID3 */ \
	{ PID_AUNIT, 0x6430, MASK_VAL(31, 24, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_P_1_MCHBAR.CHID4 */ \
	{ PID_AUNIT, 0x6434, MASK_VAL(7, 0, 0x0) }, \
	/* A_CR_CRDARB_GCNT_DEV_P_1_MCHBAR.CHID5 */ \
	{ PID_AUNIT, 0x6434, MASK_VAL(15, 8, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_P_1_MCHBAR.CHID6 */ \
	{ PID_AUNIT, 0x6434, MASK_VAL(23, 16, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_P_1_MCHBAR.CHID7 */ \
	{ PID_AUNIT, 0x6434, MASK_VAL(31, 24, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_0_MCHBAR.CHID0 */ \
	{ PID_AUNIT, 0x6438, MASK_VAL(7, 0, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_0_MCHBAR.CHID1 */ \
	{ PID_AUNIT, 0x6438, MASK_VAL(15, 8, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_0_MCHBAR.CHID2 */ \
	{ PID_AUNIT, 0x6438, MASK_VAL(23, 16, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_0_MCHBAR.CHID3 */ \
	{ PID_AUNIT, 0x6438, MASK_VAL(31, 24, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_1_MCHBAR.CHID4 */ \
	{ PID_AUNIT, 0x643c, MASK_VAL(7, 0, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_1_MCHBAR.CHID5 */ \
	{ PID_AUNIT, 0x643c, MASK_VAL(15, 8, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_1_MCHBAR.CHID6 */ \
	{ PID_AUNIT, 0x643c, MASK_VAL(23, 16, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_1_MCHBAR.CHID7 */ \
	{ PID_AUNIT, 0x643c, MASK_VAL(31, 24, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_C_0_MCHBAR.CHID0 */ \
	{ PID_AUNIT, 0x6440, MASK_VAL(7, 0, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_C_0_MCHBAR.CHID1 */ \
	{ PID_AUNIT, 0x6440, MASK_VAL(15, 8, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_C_0_MCHBAR.CHID2 */ \
	{ PID_AUNIT, 0x6440, MASK_VAL(23, 16, 0x0) }, \
	/* A_CR_CRDARB_GCNT_DEV_C_0_MCHBAR.CHID3 */ \
	{ PID_AUNIT, 0x6440, MASK_VAL(31, 24, 0x0) }, \
	/* A_CR_CRDARB_GCNT_CLS_MCHBAR.P */ \
	{ PID_AUNIT, 0x6444, MASK_VAL(7, 0, 0x1) }, \
	/* A_CR_CRDARB_GCNT_CLS_MCHBAR.NP */ \
	{ PID_AUNIT, 0x6444, MASK_VAL(15, 8, 0x1) }, \
	/* A_CR_CRDARB_GCNT_CLS_MCHBAR.C */ \
	{ PID_AUNIT, 0x6444, MASK_VAL(23, 16, 0x1) }, \
	/* A_CR_GZLQ_LIMIT_CH0_3_MCHBAR.CHID0 */ \
	{ PID_AUNIT, 0x6448, MASK_VAL(7, 0, 0x8) }, \
	/* A_CR_GZLQ_LIMIT_CH0_3_MCHBAR.CHID1 */ \
	{ PID_AUNIT, 0x6448, MASK_VAL(15, 8, 0xff) }, \
	/* A_CR_GZLQ_LIMIT_CH0_3_MCHBAR.CHID2 */ \
	{ PID_AUNIT, 0x6448, MASK_VAL(23, 16, 0xff) }, \
	/* A_CR_GZLQ_LIMIT_CH0_3_MCHBAR.CHID3 */ \
	{ PID_AUNIT, 0x6448, MASK_VAL(31, 24, 0xff) }, \
	/* A_CR_GZLQ_LIMIT_CH4_7_MCHBAR.CHID4 */ \
	{ PID_AUNIT, 0x644c, MASK_VAL(7, 0, 0xff) }, \
	/* A_CR_GZLQ_LIMIT_CH4_7_MCHBAR.CHID5 */ \
	{ PID_AUNIT, 0x644c, MASK_VAL(15, 8, 0xff) }, \
	/* A_CR_GZLQ_LIMIT_CH4_7_MCHBAR.CHID6 */ \
	{ PID_AUNIT, 0x644c, MASK_VAL(23, 16, 0xff) }, \
	/* A_CR_GZLQ_LIMIT_CH4_7_MCHBAR.CHID7 */ \
	{ PID_AUNIT, 0x644c, MASK_VAL(31, 24, 0xff) }, \
	/* A_CR_SLICE_CHANNEL_HASH_0_0_0_MCHBAR.SLICE_1_DISABLED */ \
	{ PID_AUNIT, 0x6450, MASK_VAL(0, 0, 0x0) }, \
	/* A_CR_SLICE_CHANNEL_HASH_0_0_0_MCHBAR.HVM_MODE */ \
	{ PID_AUNIT, 0x6450, MASK_VAL(1, 1, 0x0) }, \
	/* A_CR_SLICE_CHANNEL_HASH_0_0_0_MCHBAR.INTERLEAVE_MODE */ \
	{ PID_AUNIT, 0x6450, MASK_VAL(3, 2, 0x2) }, \
	/* A_CR_SLICE_CHANNEL_HASH_0_0_0_MCHBAR.SLICE_HASH_MASK */ \
	{ PID_AUNIT, 0x6450, MASK_VAL(19, 6, 0x9) }, \
	/* A_CR_SLICE_CHANNEL_HASH_0_0_0_MCHBAR.CH_HASH_MASK */ \
	{ PID_AUNIT, 0x6454, MASK_VAL(19, 6, 0x36) }, \
	/* A_CR_CHAP_SLCT1_MCHBAR.CHID_X_CNT_UPTXN */ \
	{ PID_AUNIT, 0x6484, MASK_VAL(7, 0, 0xff) }, \
	/* A_CR_CHAP_SLCT1_MCHBAR.CHID_Y_CNT_UPTXN */ \
	{ PID_AUNIT, 0x6484, MASK_VAL(23, 16, 0xff) }

#define AUNIT_VALUEFORPWRPERF_MSG_VALUES_PLATFORM_DEFAULT \
	/* A_CR_CRDARB_GCNT_DEV_P_0_MCHBAR.CHID0 */ \
	{ PID_AUNIT, 0x6430, MASK_VAL(7, 0, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_P_0_MCHBAR.CHID1 */ \
	{ PID_AUNIT, 0x6430, MASK_VAL(15, 8, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_P_0_MCHBAR.CHID2 */ \
	{ PID_AUNIT, 0x6430, MASK_VAL(23, 16, 0x0) }, \
	/* A_CR_CRDARB_GCNT_DEV_P_0_MCHBAR.CHID3 */ \
	{ PID_AUNIT, 0x6430, MASK_VAL(31, 24, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_P_1_MCHBAR.CHID4 */ \
	{ PID_AUNIT, 0x6434, MASK_VAL(7, 0, 0x0) }, \
	/* A_CR_CRDARB_GCNT_DEV_P_1_MCHBAR.CHID5 */ \
	{ PID_AUNIT, 0x6434, MASK_VAL(15, 8, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_P_1_MCHBAR.CHID6 */ \
	{ PID_AUNIT, 0x6434, MASK_VAL(23, 16, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_P_1_MCHBAR.CHID7 */ \
	{ PID_AUNIT, 0x6434, MASK_VAL(31, 24, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_0_MCHBAR.CHID0 */ \
	{ PID_AUNIT, 0x6438, MASK_VAL(7, 0, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_0_MCHBAR.CHID1 */ \
	{ PID_AUNIT, 0x6438, MASK_VAL(15, 8, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_0_MCHBAR.CHID2 */ \
	{ PID_AUNIT, 0x6438, MASK_VAL(23, 16, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_0_MCHBAR.CHID3 */ \
	{ PID_AUNIT, 0x6438, MASK_VAL(31, 24, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_1_MCHBAR.CHID4 */ \
	{ PID_AUNIT, 0x643c, MASK_VAL(7, 0, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_1_MCHBAR.CHID5 */ \
	{ PID_AUNIT, 0x643c, MASK_VAL(15, 8, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_1_MCHBAR.CHID6 */ \
	{ PID_AUNIT, 0x643c, MASK_VAL(23, 16, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_N_1_MCHBAR.CHID7 */ \
	{ PID_AUNIT, 0x643c, MASK_VAL(31, 24, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_C_0_MCHBAR.CHID0 */ \
	{ PID_AUNIT, 0x6440, MASK_VAL(7, 0, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_C_0_MCHBAR.CHID1 */ \
	{ PID_AUNIT, 0x6440, MASK_VAL(15, 8, 0x1) }, \
	/* A_CR_CRDARB_GCNT_DEV_C_0_MCHBAR.CHID2 */ \
	{ PID_AUNIT, 0x6440, MASK_VAL(23, 16, 0x0) }, \
	/* A_CR_CRDARB_GCNT_DEV_C_0_MCHBAR.CHID3 */ \
	{ PID_AUNIT, 0x6440, MASK_VAL(31, 24, 0x0) }, \
	/* A_CR_CRDARB_GCNT_CLS_MCHBAR.P */ \
	{ PID_AUNIT, 0x6444, MASK_VAL(7, 0, 0x1) }, \
	/* A_CR_CRDARB_GCNT_CLS_MCHBAR.NP */ \
	{ PID_AUNIT, 0x6444, MASK_VAL(15, 8, 0x1) }, \
	/* A_CR_CRDARB_GCNT_CLS_MCHBAR.C */ \
	{ PID_AUNIT, 0x6444, MASK_VAL(23, 16, 0x1) }, \
	/* A_CR_GZLQ_LIMIT_CH0_3_MCHBAR.CHID0 */ \
	{ PID_AUNIT, 0x6448, MASK_VAL(7, 0, 0x8) }, \
	/* A_CR_GZLQ_LIMIT_CH0_3_MCHBAR.CHID1 */ \
	{ PID_AUNIT, 0x6448, MASK_VAL(15, 8, 0xff) }, \
	/* A_CR_GZLQ_LIMIT_CH0_3_MCHBAR.CHID2 */ \
	{ PID_AUNIT, 0x6448, MASK_VAL(23, 16, 0xff) }, \
	/* A_CR_GZLQ_LIMIT_CH0_3_MCHBAR.CHID3 */ \
	{ PID_AUNIT, 0x6448, MASK_VAL(31, 24, 0xff) }, \
	/* A_CR_GZLQ_LIMIT_CH4_7_MCHBAR.CHID4 */ \
	{ PID_AUNIT, 0x644c, MASK_VAL(7, 0, 0xff) }, \
	/* A_CR_GZLQ_LIMIT_CH4_7_MCHBAR.CHID5 */ \
	{ PID_AUNIT, 0x644c, MASK_VAL(15, 8, 0xff) }, \
	/* A_CR_GZLQ_LIMIT_CH4_7_MCHBAR.CHID6 */ \
	{ PID_AUNIT, 0x644c, MASK_VAL(23, 16, 0xff) }, \
	/* A_CR_GZLQ_LIMIT_CH4_7_MCHBAR.CHID7 */ \
	{ PID_AUNIT, 0x644c, MASK_VAL(31, 24, 0xff) }, \
	/* A_CR_SLICE_CHANNEL_HASH_0_0_0_MCHBAR.SLICE_1_DISABLED */ \
	{ PID_AUNIT, 0x6450, MASK_VAL(0, 0, 0x0) }, \
	/* A_CR_SLICE_CHANNEL_HASH_0_0_0_MCHBAR.HVM_MODE */ \
	{ PID_AUNIT, 0x6450, MASK_VAL(1, 1, 0x0) }, \
	/* A_CR_SLICE_CHANNEL_HASH_0_0_0_MCHBAR.INTERLEAVE_MODE */ \
	{ PID_AUNIT, 0x6450, MASK_VAL(3, 2, 0x2) }, \
	/* A_CR_SLICE_CHANNEL_HASH_0_0_0_MCHBAR.SLICE_HASH_MASK */ \
	{ PID_AUNIT, 0x6450, MASK_VAL(19, 6, 0x9) }, \
	/* A_CR_SLICE_CHANNEL_HASH_0_0_0_MCHBAR.CH_HASH_MASK */ \
	{ PID_AUNIT, 0x6454, MASK_VAL(19, 6, 0x36) }, \
	/* A_CR_CHAP_SLCT1_MCHBAR.CHID_X_CNT_UPTXN */ \
	{ PID_AUNIT, 0x6484, MASK_VAL(7, 0, 0xff) }, \
	/* A_CR_CHAP_SLCT1_MCHBAR.CHID_Y_CNT_UPTXN */ \
	{ PID_AUNIT, 0x6484, MASK_VAL(23, 16, 0xff) }

#define BUNIT_VALUEFORPERF_MSG_VALUES_PLATFORM_DEFAULT \
	/* B_CR_BARBCTRL0.AGENT0_WEIGHT */ \
	{ PID_BUNIT, 0x6d4c, MASK_VAL(5, 0, 0x8) }, \
	/* B_CR_BARBCTRL0.AGENT1_WEIGHT */ \
	{ PID_BUNIT, 0x6d4c, MASK_VAL(13, 8, 0x8) }, \
	/* B_CR_BARBCTRL0.AGENT2_WEIGHT */ \
	{ PID_BUNIT, 0x6d4c, MASK_VAL(21, 16, 0x8) }, \
	/* B_CR_BARBCTRL0.AGENT3_WEIGHT */ \
	{ PID_BUNIT, 0x6d4c, MASK_VAL(29, 24, 0x8) }, \
	/* B_CR_BARBCTRL1.AGENT4_WEIGHT */ \
	{ PID_BUNIT, 0x6d50, MASK_VAL(5, 0, 0x8) }, \
	/* B_CR_BARBCTRL1.AGENT5_WEIGHT */ \
	{ PID_BUNIT, 0x6d50, MASK_VAL(13, 8, 0x8) }, \
	/* B_CR_BARBCTRL1.AGENT6_WEIGHT */ \
	{ PID_BUNIT, 0x6d50, MASK_VAL(21, 16, 0x8) }, \
	/* B_CR_BARBCTRL1.AGENT7_WEIGHT */ \
	{ PID_BUNIT, 0x6d50, MASK_VAL(29, 24, 0x8) }, \
	/* B_CR_BSCHWT0.AGENT0_WEIGHT */ \
	{ PID_BUNIT, 0x6d54, MASK_VAL(5, 0, 0x8) }, \
	/* B_CR_BSCHWT0.AGENT1_WEIGHT */ \
	{ PID_BUNIT, 0x6d54, MASK_VAL(13, 8, 0x8) }, \
	/* B_CR_BSCHWT0.AGENT2_WEIGHT */ \
	{ PID_BUNIT, 0x6d54, MASK_VAL(21, 16, 0x8) }, \
	/* B_CR_BSCHWT0.AGENT3_WEIGHT */ \
	{ PID_BUNIT, 0x6d54, MASK_VAL(29, 24, 0x8) }, \
	/* B_CR_BSCHWT1.AGENT4_WEIGHT */ \
	{ PID_BUNIT, 0x6d58, MASK_VAL(5, 0, 0x8) }, \
	/* B_CR_BSCHWT1.AGENT5_WEIGHT */ \
	{ PID_BUNIT, 0x6d58, MASK_VAL(13, 8, 0x8) }, \
	/* B_CR_BSCHWT1.AGENT6_WEIGHT */ \
	{ PID_BUNIT, 0x6d58, MASK_VAL(21, 16, 0x8) }, \
	/* B_CR_BSCHWT1.AGENT7_WEIGHT */ \
	{ PID_BUNIT, 0x6d58, MASK_VAL(29, 24, 0x8) }, \
	/* B_CR_BSCHWT2.AGENT8_WEIGHT */ \
	{ PID_BUNIT, 0x6d5c, MASK_VAL(5, 0, 0x8) }, \
	/* B_CR_BSCHWT2.AGENT9_WEIGHT */ \
	{ PID_BUNIT, 0x6d5c, MASK_VAL(13, 8, 0x8) }, \
	/* B_CR_BSCHWT2.AGENT10_WEIGHT */ \
	{ PID_BUNIT, 0x6d5c, MASK_VAL(21, 16, 0x8) }, \
	/* B_CR_BSCHWT2.AGENT11_WEIGHT */ \
	{ PID_BUNIT, 0x6d5c, MASK_VAL(29, 24, 0x8) }, \
	/* B_CR_BSCHWT3.AGENT12_WEIGHT */ \
	{ PID_BUNIT, 0x6d60, MASK_VAL(5, 0, 0x8) }, \
	/* B_CR_BSCHWT3.AGENT13_WEIGHT */ \
	{ PID_BUNIT, 0x6d60, MASK_VAL(13, 8, 0x8) }, \
	/* B_CR_BSCHWT3.AGENT14_WEIGHT */ \
	{ PID_BUNIT, 0x6d60, MASK_VAL(21, 16, 0x8) }, \
	/* B_CR_BSCHWT3.AGENT15_WEIGHT */ \
	{ PID_BUNIT, 0x6d60, MASK_VAL(29, 24, 0x8) }, \
	/* B_CR_BWFLUSH.DIRTY_HWM */ \
	{ PID_BUNIT, 0x6d64, MASK_VAL(7, 0, 0x1b) }, \
	/* B_CR_BWFLUSH.DIRTY_LWM */ \
	{ PID_BUNIT, 0x6d64, MASK_VAL(15, 8, 0x0) }, \
	/* B_CR_BWFLUSH.FLUSH_THRESHOLD */ \
	{ PID_BUNIT, 0x6d64, MASK_VAL(31, 24, 0x27) }, \
	/* B_CR_BFLWT.READ_WEIGHTS */ \
	{ PID_BUNIT, 0x6d68, MASK_VAL(5, 0, 0x1) }, \
	/* B_CR_BFLWT.WRITE_WEIGHTS */ \
	{ PID_BUNIT, 0x6d68, MASK_VAL(13, 8, 0x1) }, \
	/* B_CR_BFLWT.DISABLE_FLUSH_WEIGHTS */ \
	{ PID_BUNIT, 0x6d68, MASK_VAL(31, 31, 0x0) }, \
	/* B_CR_BISOCWT.NON_ISOC_REQUEST_WEIGHTS */ \
	{ PID_BUNIT, 0x6d6c, MASK_VAL(5, 0, 0xf) }, \
	/* B_CR_BISOCWT.ISOC_REQUEST_WEIGHTS */ \
	{ PID_BUNIT, 0x6d6c, MASK_VAL(13, 8, 0x3f) }, \
	/* B_CR_BISOCWT.ENABLE_ISOC_WEIGHTS */ \
	{ PID_BUNIT, 0x6d6c, MASK_VAL(31, 31, 0x1) }, \
	/* B_CR_BCTRL2.DIRTY_STALL */ \
	{ PID_BUNIT, 0x6d70, MASK_VAL(0, 0, 0x0) }

#define BUNIT_VALUEFORPOWER_MSG_VALUES_PLATFORM_DEFAULT \
	/* B_CR_BARBCTRL0.AGENT0_WEIGHT */ \
	{ PID_BUNIT, 0x6d4c, MASK_VAL(5, 0, 0x4) }, \
	/* B_CR_BARBCTRL0.AGENT1_WEIGHT */ \
	{ PID_BUNIT, 0x6d4c, MASK_VAL(13, 8, 0x4) }, \
	/* B_CR_BARBCTRL0.AGENT2_WEIGHT */ \
	{ PID_BUNIT, 0x6d4c, MASK_VAL(21, 16, 0x4) }, \
	/* B_CR_BARBCTRL0.AGENT3_WEIGHT */ \
	{ PID_BUNIT, 0x6d4c, MASK_VAL(29, 24, 0x4) }, \
	/* B_CR_BARBCTRL1.AGENT4_WEIGHT */ \
	{ PID_BUNIT, 0x6d50, MASK_VAL(5, 0, 0x4) }, \
	/* B_CR_BARBCTRL1.AGENT5_WEIGHT */ \
	{ PID_BUNIT, 0x6d50, MASK_VAL(13, 8, 0x4) }, \
	/* B_CR_BARBCTRL1.AGENT6_WEIGHT */ \
	{ PID_BUNIT, 0x6d50, MASK_VAL(21, 16, 0x4) }, \
	/* B_CR_BARBCTRL1.AGENT7_WEIGHT */ \
	{ PID_BUNIT, 0x6d50, MASK_VAL(29, 24, 0x4) }, \
	/* B_CR_BSCHWT0.AGENT0_WEIGHT */ \
	{ PID_BUNIT, 0x6d54, MASK_VAL(5, 0, 0x4) }, \
	/* B_CR_BSCHWT0.AGENT1_WEIGHT */ \
	{ PID_BUNIT, 0x6d54, MASK_VAL(13, 8, 0x4) }, \
	/* B_CR_BSCHWT0.AGENT2_WEIGHT */ \
	{ PID_BUNIT, 0x6d54, MASK_VAL(21, 16, 0x4) }, \
	/* B_CR_BSCHWT0.AGENT3_WEIGHT */ \
	{ PID_BUNIT, 0x6d54, MASK_VAL(29, 24, 0x4) }, \
	/* B_CR_BSCHWT1.AGENT4_WEIGHT */ \
	{ PID_BUNIT, 0x6d58, MASK_VAL(5, 0, 0x4) }, \
	/* B_CR_BSCHWT1.AGENT5_WEIGHT */ \
	{ PID_BUNIT, 0x6d58, MASK_VAL(13, 8, 0x4) }, \
	/* B_CR_BSCHWT1.AGENT6_WEIGHT */ \
	{ PID_BUNIT, 0x6d58, MASK_VAL(21, 16, 0x4) }, \
	/* B_CR_BSCHWT1.AGENT7_WEIGHT */ \
	{ PID_BUNIT, 0x6d58, MASK_VAL(29, 24, 0x4) }, \
	/* B_CR_BSCHWT2.AGENT8_WEIGHT */ \
	{ PID_BUNIT, 0x6d5c, MASK_VAL(5, 0, 0x4) }, \
	/* B_CR_BSCHWT2.AGENT9_WEIGHT */ \
	{ PID_BUNIT, 0x6d5c, MASK_VAL(13, 8, 0x4) }, \
	/* B_CR_BSCHWT2.AGENT10_WEIGHT */ \
	{ PID_BUNIT, 0x6d5c, MASK_VAL(21, 16, 0x4) }, \
	/* B_CR_BSCHWT2.AGENT11_WEIGHT */ \
	{ PID_BUNIT, 0x6d5c, MASK_VAL(29, 24, 0x4) }, \
	/* B_CR_BSCHWT3.AGENT12_WEIGHT */ \
	{ PID_BUNIT, 0x6d60, MASK_VAL(5, 0, 0x4) }, \
	/* B_CR_BSCHWT3.AGENT13_WEIGHT */ \
	{ PID_BUNIT, 0x6d60, MASK_VAL(13, 8, 0x4) }, \
	/* B_CR_BSCHWT3.AGENT14_WEIGHT */ \
	{ PID_BUNIT, 0x6d60, MASK_VAL(21, 16, 0x4) }, \
	/* B_CR_BSCHWT3.AGENT15_WEIGHT */ \
	{ PID_BUNIT, 0x6d60, MASK_VAL(29, 24, 0x4) }, \
	/* B_CR_BWFLUSH.DIRTY_HWM */ \
	{ PID_BUNIT, 0x6d64, MASK_VAL(7, 0, 0x0) }, \
	/* B_CR_BWFLUSH.DIRTY_LWM */ \
	{ PID_BUNIT, 0x6d64, MASK_VAL(15, 8, 0x0) }, \
	/* B_CR_BWFLUSH.FLUSH_THRESHOLD */ \
	{ PID_BUNIT, 0x6d64, MASK_VAL(31, 24, 0x0) }, \
	/* B_CR_BFLWT.READ_WEIGHTS */ \
	{ PID_BUNIT, 0x6d68, MASK_VAL(5, 0, 0x0) }, \
	/* B_CR_BFLWT.WRITE_WEIGHTS */ \
	{ PID_BUNIT, 0x6d68, MASK_VAL(13, 8, 0x0) }, \
	/* B_CR_BFLWT.DISABLE_FLUSH_WEIGHTS */ \
	{ PID_BUNIT, 0x6d68, MASK_VAL(31, 31, 0x0) }, \
	/* B_CR_BISOCWT.NON_ISOC_REQUEST_WEIGHTS */ \
	{ PID_BUNIT, 0x6d6c, MASK_VAL(5, 0, 0x0) }, \
	/* B_CR_BISOCWT.ISOC_REQUEST_WEIGHTS */ \
	{ PID_BUNIT, 0x6d6c, MASK_VAL(13, 8, 0x0) }, \
	/* B_CR_BISOCWT.ENABLE_ISOC_WEIGHTS */ \
	{ PID_BUNIT, 0x6d6c, MASK_VAL(31, 31, 0x0) }, \
	/* B_CR_BCTRL2.DIRTY_STALL */ \
	{ PID_BUNIT, 0x6d70, MASK_VAL(0, 0, 0x0) }

#define BUNIT_VALUEFORPWRPERF_MSG_VALUES_PLATFORM_DEFAULT \
	/* B_CR_BARBCTRL0.AGENT0_WEIGHT */ \
	{ PID_BUNIT, 0x6d4c, MASK_VAL(5, 0, 0x4) }, \
	/* B_CR_BARBCTRL0.AGENT1_WEIGHT */ \
	{ PID_BUNIT, 0x6d4c, MASK_VAL(13, 8, 0x4) }, \
	/* B_CR_BARBCTRL0.AGENT2_WEIGHT */ \
	{ PID_BUNIT, 0x6d4c, MASK_VAL(21, 16, 0x4) }, \
	/* B_CR_BARBCTRL0.AGENT3_WEIGHT */ \
	{ PID_BUNIT, 0x6d4c, MASK_VAL(29, 24, 0x4) }, \
	/* B_CR_BARBCTRL1.AGENT4_WEIGHT */ \
	{ PID_BUNIT, 0x6d50, MASK_VAL(5, 0, 0x4) }, \
	/* B_CR_BARBCTRL1.AGENT5_WEIGHT */ \
	{ PID_BUNIT, 0x6d50, MASK_VAL(13, 8, 0x4) }, \
	/* B_CR_BARBCTRL1.AGENT6_WEIGHT */ \
	{ PID_BUNIT, 0x6d50, MASK_VAL(21, 16, 0x4) }, \
	/* B_CR_BARBCTRL1.AGENT7_WEIGHT */ \
	{ PID_BUNIT, 0x6d50, MASK_VAL(29, 24, 0x4) }, \
	/* B_CR_BSCHWT0.AGENT0_WEIGHT */ \
	{ PID_BUNIT, 0x6d54, MASK_VAL(5, 0, 0x4) }, \
	/* B_CR_BSCHWT0.AGENT1_WEIGHT */ \
	{ PID_BUNIT, 0x6d54, MASK_VAL(13, 8, 0x4) }, \
	/* B_CR_BSCHWT0.AGENT2_WEIGHT */ \
	{ PID_BUNIT, 0x6d54, MASK_VAL(21, 16, 0x4) }, \
	/* B_CR_BSCHWT0.AGENT3_WEIGHT */ \
	{ PID_BUNIT, 0x6d54, MASK_VAL(29, 24, 0x4) }, \
	/* B_CR_BSCHWT1.AGENT4_WEIGHT */ \
	{ PID_BUNIT, 0x6d58, MASK_VAL(5, 0, 0x4) }, \
	/* B_CR_BSCHWT1.AGENT5_WEIGHT */ \
	{ PID_BUNIT, 0x6d58, MASK_VAL(13, 8, 0x4) }, \
	/* B_CR_BSCHWT1.AGENT6_WEIGHT */ \
	{ PID_BUNIT, 0x6d58, MASK_VAL(21, 16, 0x4) }, \
	/* B_CR_BSCHWT1.AGENT7_WEIGHT */ \
	{ PID_BUNIT, 0x6d58, MASK_VAL(29, 24, 0x4) }, \
	/* B_CR_BSCHWT2.AGENT8_WEIGHT */ \
	{ PID_BUNIT, 0x6d5c, MASK_VAL(5, 0, 0x4) }, \
	/* B_CR_BSCHWT2.AGENT9_WEIGHT */ \
	{ PID_BUNIT, 0x6d5c, MASK_VAL(13, 8, 0x4) }, \
	/* B_CR_BSCHWT2.AGENT10_WEIGHT */ \
	{ PID_BUNIT, 0x6d5c, MASK_VAL(21, 16, 0x4) }, \
	/* B_CR_BSCHWT2.AGENT11_WEIGHT */ \
	{ PID_BUNIT, 0x6d5c, MASK_VAL(29, 24, 0x4) }, \
	/* B_CR_BSCHWT3.AGENT12_WEIGHT */ \
	{ PID_BUNIT, 0x6d60, MASK_VAL(5, 0, 0x4) }, \
	/* B_CR_BSCHWT3.AGENT13_WEIGHT */ \
	{ PID_BUNIT, 0x6d60, MASK_VAL(13, 8, 0x4) }, \
	/* B_CR_BSCHWT3.AGENT14_WEIGHT */ \
	{ PID_BUNIT, 0x6d60, MASK_VAL(21, 16, 0x4) }, \
	/* B_CR_BSCHWT3.AGENT15_WEIGHT */ \
	{ PID_BUNIT, 0x6d60, MASK_VAL(29, 24, 0x4) }, \
	/* B_CR_BWFLUSH.DIRTY_HWM */ \
	{ PID_BUNIT, 0x6d64, MASK_VAL(7, 0, 0x0) }, \
	/* B_CR_BWFLUSH.DIRTY_LWM */ \
	{ PID_BUNIT, 0x6d64, MASK_VAL(15, 8, 0x0) }, \
	/* B_CR_BWFLUSH.FLUSH_THRESHOLD */ \
	{ PID_BUNIT, 0x6d64, MASK_VAL(31, 24, 0x0) }, \
	/* B_CR_BFLWT.READ_WEIGHTS */ \
	{ PID_BUNIT, 0x6d68, MASK_VAL(5, 0, 0x0) }, \
	/* B_CR_BFLWT.WRITE_WEIGHTS */ \
	{ PID_BUNIT, 0x6d68, MASK_VAL(13, 8, 0x0) }, \
	/* B_CR_BFLWT.DISABLE_FLUSH_WEIGHTS */ \
	{ PID_BUNIT, 0x6d68, MASK_VAL(31, 31, 0x0) }, \
	/* B_CR_BISOCWT.NON_ISOC_REQUEST_WEIGHTS */ \
	{ PID_BUNIT, 0x6d6c, MASK_VAL(5, 0, 0x0) }, \
	/* B_CR_BISOCWT.ISOC_REQUEST_WEIGHTS */ \
	{ PID_BUNIT, 0x6d6c, MASK_VAL(13, 8, 0x0) }, \
	/* B_CR_BISOCWT.ENABLE_ISOC_WEIGHTS */ \
	{ PID_BUNIT, 0x6d6c, MASK_VAL(31, 31, 0x0) }, \
	/* B_CR_BCTRL2.DIRTY_STALL */ \
	{ PID_BUNIT, 0x6d70, MASK_VAL(0, 0, 0x0) }

#define TUNIT_VALUEFORPERF_MSG_VALUES_PLATFORM_DEFAULT \
	/* CTL_MCHBAR.ALWAYS_SNP_PII2 */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(0, 0, 0x0) }, \
	/* CTL_MCHBAR.OUTSTND_SNP */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(1, 1, 0x0) }, \
	/* CTL_MCHBAR.DIS_LIVE_BRAM_BYP_IDI */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(2, 2, 0x0) }, \
	/* CTL_MCHBAR.ALWAYS_SNP_IDI */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(3, 3, 0x0) }, \
	/* CTL_MCHBAR.SNPINV */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(7, 7, 0x0) }, \
	/* CTL_MCHBAR.DISABLE_ISOC_HIGHPRI_RDDATA_RETURN */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(18, 18, 0x0) }, \
	/* CTL_MCHBAR.DISABLE_OPPORTUNISTIC_SLICE1_SCHEDULE */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(19, 19, 0x0) }, \
	/* CTL_MCHBAR.DISABLE_SNOOPING_GT */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(20, 20, 0x0) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VC0A_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(0, 0, 0x1) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VC0B_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(1, 1, 0x1) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VC1A_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(2, 2, 0x0) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VC1B_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(3, 3, 0x0) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VC2A_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(4, 4, 0x0) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VC2B_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(5, 5, 0x1) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VC2C_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(6, 6, 0x1) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VCBR_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(7, 7, 0x1) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VC0A_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(0, 0, 0x1) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VC0B_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(1, 1, 0x1) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VC1A_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(2, 2, 0x0) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VC1B_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(3, 3, 0x0) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VC2A_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(4, 4, 0x1) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VC2B_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(5, 5, 0x1) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VC2C_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(6, 6, 0x1) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VCBR_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(7, 7, 0x1) }, \
	/* T_CR_CTL.ALWAYS_SNP_PII2 */ \
	{ PID_TUNIT, 0x523c, MASK_VAL(0, 0, 0x0) }, \
	/* T_CR_CTL.DIS_LIVE_BRAM_BYP_IDI */ \
	{ PID_TUNIT, 0x523c, MASK_VAL(2, 2, 0x0) }, \
	/* T_CR_CTL.ALWAYS_SNP_IDI */ \
	{ PID_TUNIT, 0x523c, MASK_VAL(3, 3, 0x0) }, \
	/* T_CR_CTL.DISABLE_ISOC_HIGHPRI_RDDATA_RETURN */ \
	{ PID_TUNIT, 0x523c, MASK_VAL(18, 18, 0x0) }, \
	/* T_CR_CTL.DISABLE_OPPORTUNISTIC_SLICE1_SCHEDULE */ \
	{ PID_TUNIT, 0x523c, MASK_VAL(19, 19, 0x0) }, \
	/* T_CR_CTL.DISABLE_SNOOPING_GT */ \
	{ PID_TUNIT, 0x523c, MASK_VAL(20, 20, 0x0) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VC0A_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(0, 0, 0x1) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VC0B_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(1, 1, 0x1) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VC1A_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(2, 2, 0x0) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VC1B_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(3, 3, 0x0) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VC2A_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(4, 4, 0x1) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VC2B_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(5, 5, 0x1) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VC2C_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(6, 6, 0x1) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VCBR_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(7, 7, 0x1) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VC0A_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(0, 0, 0x1) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VC0B_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(1, 1, 0x1) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VC1A_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(2, 2, 0x0) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VC1B_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(3, 3, 0x0) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VC2A_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(4, 4, 0x1) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VC2B_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(5, 5, 0x1) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VC2C_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(6, 6, 0x1) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VCBR_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(7, 7, 0x1) }

#define TUNIT_VALUEFORPOWER_MSG_VALUES_PLATFORM_DEFAULT \
	/* CTL_MCHBAR.ALWAYS_SNP_PII2 */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(0, 0, 0x0) }, \
	/* CTL_MCHBAR.OUTSTND_SNP */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(1, 1, 0x0) }, \
	/* CTL_MCHBAR.DIS_LIVE_BRAM_BYP_IDI */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(2, 2, 0x0) }, \
	/* CTL_MCHBAR.ALWAYS_SNP_IDI */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(3, 3, 0x0) }, \
	/* CTL_MCHBAR.SNPINV */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(7, 7, 0x0) }, \
	/* CTL_MCHBAR.DISABLE_ISOC_HIGHPRI_RDDATA_RETURN */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(18, 18, 0x0) }, \
	/* CTL_MCHBAR.DISABLE_OPPORTUNISTIC_SLICE1_SCHEDULE */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(19, 19, 0x0) }, \
	/* CTL_MCHBAR.DISABLE_SNOOPING_GT */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(20, 20, 0x0) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VC0A_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(0, 0, 0x1) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VC0B_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(1, 1, 0x1) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VC1A_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(2, 2, 0x0) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VC1B_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(3, 3, 0x0) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VC2A_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(4, 4, 0x1) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VC2B_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(5, 5, 0x1) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VC2C_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(6, 6, 0x1) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VCBR_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(7, 7, 0x1) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VC0A_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(0, 0, 0x1) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VC0B_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(1, 1, 0x1) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VC1A_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(2, 2, 0x0) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VC1B_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(3, 3, 0x0) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VC2A_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(4, 4, 0x1) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VC2B_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(5, 5, 0x1) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VC2C_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(6, 6, 0x1) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VCBR_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(7, 7, 0x1) }, \
	/* T_CR_CTL.ALWAYS_SNP_PII2 */ \
	{ PID_TUNIT, 0x523c, MASK_VAL(0, 0, 0x0) }, \
	/* T_CR_CTL.DIS_LIVE_BRAM_BYP_IDI */ \
	{ PID_TUNIT, 0x523c, MASK_VAL(2, 2, 0x0) }, \
	/* T_CR_CTL.ALWAYS_SNP_IDI */ \
	{ PID_TUNIT, 0x523c, MASK_VAL(3, 3, 0x0) }, \
	/* T_CR_CTL.DISABLE_ISOC_HIGHPRI_RDDATA_RETURN */ \
	{ PID_TUNIT, 0x523c, MASK_VAL(18, 18, 0x0) }, \
	/* T_CR_CTL.DISABLE_OPPORTUNISTIC_SLICE1_SCHEDULE */ \
	{ PID_TUNIT, 0x523c, MASK_VAL(19, 19, 0x0) }, \
	/* T_CR_CTL.DISABLE_SNOOPING_GT */ \
	{ PID_TUNIT, 0x523c, MASK_VAL(20, 20, 0x0) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VC0A_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(0, 0, 0x1) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VC0B_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(1, 1, 0x1) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VC1A_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(2, 2, 0x0) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VC1B_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(3, 3, 0x0) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VC2A_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(4, 4, 0x1) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VC2B_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(5, 5, 0x1) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VC2C_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(6, 6, 0x1) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VCBR_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(7, 7, 0x1) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VC0A_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(0, 0, 0x1) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VC0B_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(1, 1, 0x1) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VC1A_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(2, 2, 0x0) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VC1B_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(3, 3, 0x0) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VC2A_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(4, 4, 0x1) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VC2B_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(5, 5, 0x1) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VC2C_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(6, 6, 0x1) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VCBR_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(7, 7, 0x1) }

#define TUNIT_VALUEFORPWRPERF_MSG_VALUES_PLATFORM_DEFAULT \
	/* CTL_MCHBAR.ALWAYS_SNP_PII2 */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(0, 0, 0x0) }, \
	/* CTL_MCHBAR.OUTSTND_SNP */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(1, 1, 0x0) }, \
	/* CTL_MCHBAR.DIS_LIVE_BRAM_BYP_IDI */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(2, 2, 0x0) }, \
	/* CTL_MCHBAR.ALWAYS_SNP_IDI */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(3, 3, 0x0) }, \
	/* CTL_MCHBAR.SNPINV */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(7, 7, 0x0) }, \
	/* CTL_MCHBAR.DISABLE_ISOC_HIGHPRI_RDDATA_RETURN */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(18, 18, 0x0) }, \
	/* CTL_MCHBAR.DISABLE_OPPORTUNISTIC_SLICE1_SCHEDULE */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(19, 19, 0x0) }, \
	/* CTL_MCHBAR.DISABLE_SNOOPING_GT */ \
	{ PID_TUNIT, 0x7810, MASK_VAL(20, 20, 0x0) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VC0A_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(0, 0, 0x1) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VC0B_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(1, 1, 0x1) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VC1A_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(2, 2, 0x0) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VC1B_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(3, 3, 0x0) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VC2A_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(4, 4, 0x1) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VC2B_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(5, 5, 0x1) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VC2C_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(6, 6, 0x1) }, \
	/* VC_READ_ORDERING_CFG_MCHBAR.UPSTREAM_VCBR_IN_ORDER */ \
	{ PID_TUNIT, 0x781c, MASK_VAL(7, 7, 0x1) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VC0A_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(0, 0, 0x1) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VC0B_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(1, 1, 0x1) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VC1A_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(2, 2, 0x0) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VC1B_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(3, 3, 0x0) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VC2A_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(4, 4, 0x1) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VC2B_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(5, 5, 0x1) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VC2C_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(6, 6, 0x1) }, \
	/* VC_WRITE_ORDERING_CFG_MCHBAR.UPSTREAM_VCBR_IN_ORDER */ \
	{ PID_TUNIT, 0x7820, MASK_VAL(7, 7, 0x1) }, \
	/* T_CR_CTL.ALWAYS_SNP_PII2 */ \
	{ PID_TUNIT, 0x523c, MASK_VAL(0, 0, 0x0) }, \
	/* T_CR_CTL.DIS_LIVE_BRAM_BYP_IDI */ \
	{ PID_TUNIT, 0x523c, MASK_VAL(2, 2, 0x0) }, \
	/* T_CR_CTL.ALWAYS_SNP_IDI */ \
	{ PID_TUNIT, 0x523c, MASK_VAL(3, 3, 0x0) }, \
	/* T_CR_CTL.DISABLE_ISOC_HIGHPRI_RDDATA_RETURN */ \
	{ PID_TUNIT, 0x523c, MASK_VAL(18, 18, 0x0) }, \
	/* T_CR_CTL.DISABLE_OPPORTUNISTIC_SLICE1_SCHEDULE */ \
	{ PID_TUNIT, 0x523c, MASK_VAL(19, 19, 0x0) }, \
	/* T_CR_CTL.DISABLE_SNOOPING_GT */ \
	{ PID_TUNIT, 0x523c, MASK_VAL(20, 20, 0x0) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VC0A_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(0, 0, 0x1) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VC0B_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(1, 1, 0x1) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VC1A_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(2, 2, 0x0) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VC1B_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(3, 3, 0x0) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VC2A_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(4, 4, 0x1) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VC2B_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(5, 5, 0x1) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VC2C_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(6, 6, 0x1) }, \
	/* T_CR_VC_READ_ORDERING_CFG.UPSTREAM_VCBR_IN_ORDER */ \
	{ PID_TUNIT, 0x5288, MASK_VAL(7, 7, 0x1) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VC0A_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(0, 0, 0x1) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VC0B_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(1, 1, 0x1) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VC1A_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(2, 2, 0x0) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VC1B_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(3, 3, 0x0) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VC2A_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(4, 4, 0x1) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VC2B_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(5, 5, 0x1) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VC2C_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(6, 6, 0x1) }, \
	/* T_CR_VC_WRITE_ORDERING_CFG.UPSTREAM_VCBR_IN_ORDER */ \
	{ PID_TUNIT, 0x528c, MASK_VAL(7, 7, 0x1) }

#define VALUEFORPWRPERF_MSG_VALUES_PLATFORM_DEFAULT \
	AUNIT_VALUEFORPWRPERF_MSG_VALUES_PLATFORM_DEFAULT, \
	BUNIT_VALUEFORPWRPERF_MSG_VALUES_PLATFORM_DEFAULT, \
	TUNIT_VALUEFORPWRPERF_MSG_VALUES_PLATFORM_DEFAULT

#define VALUEFORPOWER_MSG_VALUES_PLATFORM_DEFAULT \
	AUNIT_VALUEFORPOWER_MSG_VALUES_PLATFORM_DEFAULT, \
	BUNIT_VALUEFORPOWER_MSG_VALUES_PLATFORM_DEFAULT, \
	TUNIT_VALUEFORPOWER_MSG_VALUES_PLATFORM_DEFAULT

#define VALUEFORPERF_MSG_VALUES_PLATFORM_DEFAULT \
	AUNIT_VALUEFORPERF_MSG_VALUES_PLATFORM_DEFAULT, \
	BUNIT_VALUEFORPERF_MSG_VALUES_PLATFORM_DEFAULT, \
	TUNIT_VALUEFORPERF_MSG_VALUES_PLATFORM_DEFAULT

#endif /* _SOC_APOLLOLAKE_PNPCONFIG_H_ */
