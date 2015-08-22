/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2013 Google Inc.
 * Copyright (C) 2015 Intel Corp.
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

#ifndef _SOC_GPIO_DEFS_H_
#define _SOC_GPIO_DEFS_H_

/* GPSOUTHWEST */
#define GP_SW_00	0
#define GP_SW_01	1
#define GP_SW_02	2
#define GP_SW_03	3
#define GP_SW_04	4
#define GP_SW_05	5
#define GP_SW_06	6
#define GP_SW_07	7
#define GP_SW_15	8
#define GP_SW_16	9
#define GP_SW_17	10
#define GP_SW_18	11
#define GP_SW_19	12
#define GP_SW_20	13
#define GP_SW_21	14
#define GP_SW_22	15
#define GP_SW_30	16
#define GP_SW_31	17
#define GP_SW_32	18
#define GP_SW_33	19
#define GP_SW_34	20
#define GP_SW_35	21
#define GP_SW_36	22
#define GP_SW_37	23
#define GP_SW_45	24
#define GP_SW_46	25
#define GP_SW_47	26
#define GP_SW_48	27
#define GP_SW_49	28
#define GP_SW_50	29
#define GP_SW_51	30
#define GP_SW_52	31
#define GP_SW_60	32
#define GP_SW_61	33
#define GP_SW_62	34
#define GP_SW_63	35
#define GP_SW_64	36
#define GP_SW_65	37
#define GP_SW_66	38
#define GP_SW_67	39
#define GP_SW_75	40
#define GP_SW_76	41
#define GP_SW_77	42
#define GP_SW_78	43
#define GP_SW_79	44
#define GP_SW_80	45
#define GP_SW_81	46
#define GP_SW_82	47
#define GP_SW_90	48
#define GP_SW_91	49
#define GP_SW_92	50
#define GP_SW_93	51
#define GP_SW_94	52
#define GP_SW_95	53
#define GP_SW_96	54
#define GP_SW_97	55
/* GPNORTH */
#define GP_NC_00	56
#define GP_NC_01	57
#define GP_NC_02	58
#define GP_NC_03	59
#define GP_NC_04	60
#define GP_NC_05	61
#define GP_NC_06	62
#define GP_NC_07	63
#define GP_NC_08	64
#define GP_NC_15	65
#define GP_NC_16	66
#define GP_NC_17	67
#define GP_NC_18	68
#define GP_NC_19	69
#define GP_NC_20	70
#define GP_NC_21	71
#define GP_NC_22	72
#define GP_NC_23	73
#define GP_NC_24	74
#define GP_NC_25	75
#define GP_NC_26	76
#define GP_NC_27	77
#define GP_NC_30	78
#define GP_NC_31	79
#define GP_NC_32	80
#define GP_NC_33	81
#define GP_NC_34	82
#define GP_NC_35	83
#define GP_NC_36	84
#define GP_NC_37	85
#define GP_NC_38	86
#define GP_NC_39	87
#define GP_NC_40	88
#define GP_NC_41	89
#define GP_NC_45	90
#define GP_NC_46	91
#define GP_NC_47	92
#define GP_NC_48	93
#define GP_NC_49	94
#define GP_NC_50	95
#define GP_NC_51	96
#define GP_NC_52	97
#define GP_NC_53	98
#define GP_NC_54	99
#define GP_NC_55	100
#define GP_NC_56	101
#define GP_NC_60	102
#define GP_NC_61	103
#define GP_NC_62	104
#define GP_NC_63	105
#define GP_NC_64	106
#define GP_NC_65	107
#define GP_NC_66	108
#define GP_NC_67	119
#define GP_NC_68	110
#define GP_NC_69	111
#define GP_NC_70	112
#define GP_NC_71	113
#define GP_NC_72	114
/* GPEAST */
#define GP_E_00	115
#define GP_E_01	116
#define GP_E_02	117
#define GP_E_03	118
#define GP_E_04	119
#define GP_E_05	120
#define GP_E_06	121
#define GP_E_07	122
#define GP_E_08	123
#define GP_E_09	124
#define GP_E_10	125
#define GP_E_11	126
#define GP_E_15	127
#define GP_E_16	128
#define GP_E_17	129
#define GP_E_18	130
#define GP_E_19	131
#define GP_E_20	132
#define GP_E_21	133
#define GP_E_22	134
#define GP_E_23	135
#define GP_E_24	136
#define GP_E_25	137
#define GP_E_26	138
/* GPSOUTHEAST */
#define GP_SE_00	139
#define GP_SE_01	140
#define GP_SE_02	141
#define GP_SE_03	142
#define GP_SE_04	143
#define GP_SE_05	144
#define GP_SE_06	145
#define GP_SE_07	146
#define GP_SE_15	147
#define GP_SE_16	148
#define GP_SE_17	149
#define GP_SE_18	150
#define GP_SE_19	151
#define GP_SE_20	152
#define GP_SE_21	153
#define GP_SE_22	154
#define GP_SE_23	155
#define GP_SE_24	156
#define GP_SE_25	157
#define GP_SE_26	158
#define GP_SE_30	159
#define GP_SE_31	160
#define GP_SE_32	161
#define GP_SE_33	162
#define GP_SE_34	163
#define GP_SE_35	164
#define GP_SE_45	165
#define GP_SE_46	166
#define GP_SE_47	167
#define GP_SE_48	168
#define GP_SE_49	169
#define GP_SE_50	170
#define GP_SE_51	171
#define GP_SE_52	172
#define GP_SE_60	173
#define GP_SE_61	174
#define GP_SE_62	175
#define GP_SE_63	176
#define GP_SE_64	177
#define GP_SE_65	178
#define GP_SE_66	179
#define GP_SE_67	180
#define GP_SE_68	181
#define GP_SE_69	182
#define GP_SE_75	183
#define GP_SE_76	184
#define GP_SE_77	185
#define GP_SE_78	186
#define GP_SE_79	187
#define GP_SE_80	188
#define GP_SE_81	189
#define GP_SE_82	190
#define GP_SE_83	191
#define GP_SE_84	192
#define GP_SE_85	193

#endif /* _SOC_GPIO_DEFS_H_ */
