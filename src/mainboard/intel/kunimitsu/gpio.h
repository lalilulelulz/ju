/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2013 Google Inc.
 * Copyright (C) 2015 Intel Corporation
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc.
 */

#ifndef _GPIO_H_
#define _GPIO_H_

#include <soc/gpio.h>

const GPIO_INIT_CONFIG GpioTableKunimitsu[] = {
{GPIO_LP_GPP_A0, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_A1, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_A2, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut,
	GpioOutDefault, GpioIntDis, GpioTermNone}},
{GPIO_LP_GPP_A3, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_A4, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_A5, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_A6, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_A8, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_A9, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_A16, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_A17, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirNone,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_B2, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntEdge, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_B3, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, (GpioIntApic|GpioIntLevel), GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_B6, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntLevel, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_B7, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntLevel, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_B9, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntLevel, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_B12, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutHigh, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_B13, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutHigh, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_B15, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,
	GpioOutLow, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_B16, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntEdge, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_B17, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_B19, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_B20, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_B21, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_B22, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_C0, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_C1, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_C3, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,
	GpioOutLow,GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_C6, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntLevel, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_C7, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,
	GpioOutHigh,GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_C11, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,
	GpioOutLow,GpioIntDis, GpioResetDeep, GpioTermWpd20K}},
{GPIO_LP_GPP_C12, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_C13, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_C14, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_C15, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_C16, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_C17, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_C18, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_C19, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_C20, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_C21, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_C22, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,
	GpioOutHigh,GpioIntDis, GpioResetDeep, GpioTermWpd20K}},
{GPIO_LP_GPP_C23, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntLevel, GpioResetDeep, GpioTermWpu20K}},
{GPIO_LP_GPP_D10, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,
	GpioOutLow,GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_D11, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,
	GpioOutLow,GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_D14, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntEdge, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_D17, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_D18, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_D19, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_D20, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_D23, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_E0, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntEdge, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_E6, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutHigh, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_E7, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, (GpioIntApic|GpioIntLevel), GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_E9, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntLevel, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_E10, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntLevel, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_E11, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntLevel, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_E12, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntLevel, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_E13, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntLevel, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_E14, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntLevel, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_E15, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntEdge, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_E16, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntEdge, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_E17, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntLevel, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_E23, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut,
	GpioOutHigh,GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_F0, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_F1, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_F2, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_F3, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_F8, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_F9, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_F10, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirInInv,
	GpioOutDefault, GpioIntApic | GpioIntEdge, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_F12, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_F13, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_F14, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_F15, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_F16, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_F17, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_F18, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_F19, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_F20, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_F21, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_F22, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_F23, {GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntLevel, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_G0, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_G1, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_G2, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_G3, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_G4, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_G5, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPP_G6, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntEdge, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPD1, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntLevel, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPD2, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntEdge, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPD3, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn,
	GpioOutDefault, GpioIntLevel, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPD4, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutHigh, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPD5, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutHigh, GpioIntDis, GpioResetDeep, GpioTermNone}},
{GPIO_LP_GPD8, {GpioPadModeNative1, GpioHostOwnGpio, GpioDirOut,
	GpioOutLow,GpioIntDis, GpioResetDeep, GpioTermNone}},
{END_OF_GPIO_TABLE,  {GpioPadModeGpio, GpioHostOwnGpio, GpioDirNone,
	GpioOutDefault, GpioIntDis, GpioResetPwrGood,  GpioTermNone}},
};
#endif
