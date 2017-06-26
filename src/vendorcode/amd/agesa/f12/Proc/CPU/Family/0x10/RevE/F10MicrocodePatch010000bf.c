/* $NoKeywords:$ */
/**
 * @file
 *
 * AMD Family_10 Microcode patch.
 *
 * Fam10 Microcode Patch rev 010000bf for 10a0 or equivalent.
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AGESA
 * @e sub-project:  CPU/FAMILY/0x10/REVC
 * @e \$Revision: 44324 $   @e \$Date: 2010-12-22 17:16:51 +0800 (Wed, 22 Dec 2010) $
 *
 */
/*
 ******************************************************************************
 *
 * Copyright (c) 2011, Advanced Micro Devices, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Advanced Micro Devices, Inc. nor the names of
 *       its contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ADVANCED MICRO DEVICES, INC. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************
 */
/*----------------------------------------------------------------------------------------
 *                             M O D U L E S    U S E D
 *----------------------------------------------------------------------------------------
 */
#include "AGESA.h"
#include "cpuRegisters.h"
#include "cpuEarlyInit.h"
CODE_GROUP (G1_PEICC)
RDATA_GROUP (G1_PEICC)


/*----------------------------------------------------------------------------------------
 *                   D E F I N I T I O N S    A N D    M A C R O S
 *----------------------------------------------------------------------------------------
 */

/*----------------------------------------------------------------------------------------
 *                  T Y P E D E F S     A N D     S T R U C T U R E S
 *----------------------------------------------------------------------------------------
 */

// Patch code 010000bf for 10a0 and equivalent
CONST MICROCODE_PATCHES ROMDATA CpuF10MicrocodePatch010000bf =
{{
0x10,
0x20,
0x17,
0x02,
0xbf,
0x00,
0x00,
0x01,
0x00,
0x80,
0x20,
0x00,
0x42,
0x82,
0x02,
0x39,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0xa0,
0x10,
0x00,
0x00,
0x00,
0xaa,
0xaa,
0xaa,
0x74,
0x0f,
0x00,
0x00,
0xbe,
0x01,
0x00,
0x00,
0x33,
0x0e,
0x00,
0x00,
0xa9,
0x01,
0x00,
0x00,
0x75,
0x00,
0x00,
0x00,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xff,
0xa0,
0xfd,
0xff,
0x28,
0xc3,
0x3f,
0xc0,
0xcf,
0xff,
0x07,
0xe2,
0x01,
0x0f,
0xde,
0x50,
0xfe,
0xf2,
0xdf,
0xff,
0x0f,
0x3b,
0xfc,
0x01,
0xc5,
0x40,
0x03,
0xd4,
0x00,
0x80,
0xff,
0xfe,
0x7f,
0xfe,
0xe1,
0x1b,
0xc8,
0x5b,
0xf6,
0xff,
0xff,
0x7b,
0x87,
0x5f,
0xad,
0x6b,
0xf9,
0x6f,
0xfe,
0xfa,
0x1f,
0xfe,
0xb5,
0x00,
0x40,
0x11,
0x6a,
0x0e,
0xc0,
0x9b,
0x56,
0xe8,
0x75,
0xe0,
0x0f,
0x38,
0x00,
0xcf,
0xcc,
0xa0,
0xd7,
0x83,
0x3f,
0xff,
0x7b,
0xfc,
0xbf,
0x00,
0x3f,
0x0f,
0xff,
0x35,
0x00,
0x80,
0xd0,
0x18,
0x07,
0x60,
0x19,
0x07,
0xf4,
0x7a,
0xf0,
0xa6,
0x1c,
0x00,
0x38,
0x1f,
0xc0,
0xe7,
0xa0,
0xff,
0xff,
0x51,
0x9e,
0x7f,
0x80,
0x9f,
0x87,
0x80,
0x0a,
0x00,
0x60,
0xd3,
0xe0,
0x4f,
0x10,
0xfc,
0x32,
0xd8,
0x3a,
0x49,
0xff,
0x7f,
0xcb,
0xf0,
0x0f,
0xf0,
0xf3,
0x8c,
0xff,
0xff,
0x00,
0xc3,
0x31,
0x17,
0xfd,
0x2c,
0x47,
0x0d,
0x00,
0xd0,
0x32,
0xf0,
0x27,
0x1d,
0x7e,
0x19,
0x6c,
0x60,
0xf1,
0xff,
0x1f,
0x7f,
0x38,
0xe6,
0xa2,
0x16,
0x35,
0xff,
0xff,
0xe7,
0xe1,
0x1f,
0xe0,
0x00,
0xfe,
0xbf,
0x07,
0xbb,
0x9c,
0xf4,
0xff,
0x3f,
0x0f,
0xff,
0x00,
0x07,
0xf8,
0xdf,
0x8d,
0x0b,
0x3e,
0x78,
0x73,
0x3f,
0x8b,
0xff,
0xff,
0x70,
0xe5,
0xf0,
0x0b,
0x03,
0x00,
0x0f,
0x50,
0xff,
0x52,
0xfe,
0xbb,
0xaf,
0xfa,
0x87,
0x7f,
0xff,
0x07,
0xc0,
0xff,
0xa5,
0x14,
0x1f,
0xbe,
0xff,
0x9f,
0xc5,
0xff,
0xc4,
0xaa,
0x72,
0xf8,
0xef,
0x01,
0x80,
0xff,
0xeb,
0xff,
0x00,
0x43,
0x37,
0x96,
0xfd,
0xc3,
0xf6,
0xff,
0xab,
0x80,
0xff,
0x00,
0x3f,
0x0f,
0xff,
0xff,
0x8f,
0xe2,
0xfc,
0x02,
0x54,
0x39,
0xda,
0xd5,
0x00,
0x80,
0xff,
0x68,
0x3c,
0xe0,
0xc1,
0x9b,
0xca,
0xfe,
0xe4,
0xff,
0xff,
0x09,
0x87,
0x5f,
0x06,
0x5b,
0xfe,
0x0f,
0xc4,
0x03,
0x1e,
0xfa,
0xa9,
0x7c,
0xe0,
0xff,
0x7b,
0x00,
0xc0,
0x7f,
0xe0,
0x1f,
0xdf,
0xf0,
0x0f,
0xe0,
0x00,
0xff,
0x81,
0x7f,
0x7f,
0xc3,
0x3f,
0x80,
0x01,
0xfc,
0x07,
0xfe,
0xfe,
0x0d,
0xff,
0x00,
0x00,
0xf0,
0xff,
0x3d,
0x0f,
0xe0,
0x3f,
0xf0,
0xf0,
0x6f,
0xf8,
0x07,
0x3f,
0x80,
0xff,
0xc0,
0xc0,
0xbf,
0xe1,
0x1f,
0xff,
0x00,
0xfe,
0x03,
0x00,
0xff,
0x86,
0x7f,
0x1e,
0x00,
0xf8,
0xff,
0xf8,
0x07,
0xf0,
0x1f,
0x03,
0xf8,
0x37,
0xfc,
0xe0,
0x1f,
0xc0,
0x7f,
0x0f,
0xe0,
0xdf,
0xf0,
0x81,
0x7f,
0x00,
0xff,
0x3f,
0x80,
0x7f,
0xc3,
0x7f,
0x0f,
0x00,
0xfc,
0x0f,
0xfc,
0x03,
0xf8,
0xfe,
0x01,
0xfc,
0x1b,
0x3f,
0xf0,
0x0f,
0xe0,
0xf8,
0x07,
0xf0,
0x6f,
0xff,
0xc0,
0x3f,
0x80,
0xe1,
0x1f,
0xc0,
0xbf,
0xfe,
0xbf,
0x07,
0x00,
0xfc,
0x07,
0xfe,
0x01,
0x0d,
0xff,
0x00,
0xfe,
0xf0,
0x1f,
0xf8,
0x07,
0x37,
0xfc,
0x03,
0xf8,
0xc0,
0x7f,
0xe0,
0x1f,
0xdf,
0xf0,
0x0f,
0xe0,
0x00,
0xff,
0xdf,
0x03,
0x00,
0xfe,
0x03,
0xff,
0xff,
0x86,
0x7f,
0x00,
0x03,
0xf8,
0x0f,
0xfc,
0xfc,
0x1b,
0xfe,
0x01,
0x0f,
0xe0,
0x3f,
0xf0,
0xf0,
0x6f,
0xf8,
0x07,
0x01,
0x80,
0xff,
0xef,
0x7f,
0xbf,
0xff,
0x81,
0xdf,
0x95,
0xc1,
0xaf,
0xff,
0x91,
0xfc,
0x2f,
0x48,
0x57,
0x06,
0xbf,
0xff,
0x4f,
0xb0,
0xff,
0x32,
0xd8,
0x3a,
0xfc,
0xd7,
0x00,
0x40,
0x95,
0x81,
0xff,
0x94,
0x01,
0x1f,
0xe0,
0xe7,
0xe1,
0xff,
0xff,
0x53,
0xce,
0x7f,
0xa9,
0xeb,
0x83,
0xff,
0xef,
0x4b,
0xfd,
0xfc,
0xbd,
0xbd,
0x0e,
0xff,
0x7b,
0x00,
0xe0,
0x9c,
0x56,
0x0e,
0x00,
0xd0,
0x0f,
0xe0,
0x73,
0xff,
0x81,
0x7f,
0x00,
0xc3,
0x3f,
0x80,
0x7f,
0xfc,
0x07,
0xfe,
0x01,
0x0d,
0xff,
0x00,
0xfe,
0xe0,
0xfd,
0x35,
0x00,
0xe0,
0x0d,
0x2b,
0x07,
0x3a,
0xf0,
0x07,
0xf4,
0x96,
0xff,
0xed,
0x3f,
0xff,
0xe1,
0x1f,
0xab,
0x5b,
0x02,
0x00,
0xfe,
0xfb,
0x87,
0x7f,
0xac,
0x00,
0xa8,
0xcd,
0x1a,
0x6f,
0x72,
0xc0,
0xff,
0xfc,
0x3c,
0xfc,
0x03,
0x1f,
0xc0,
0x7f,
0xe0,
0xe0,
0xdf,
0xf0,
0x0f,
0x7f,
0x00,
0xff,
0x81,
0x80,
0x7f,
0xc3,
0x3f,
0x0f,
0x00,
0xfc,
0x7f,
0xff,
0x7f,
0x79,
0xfc,
0x01,
0x7e,
0x1e,
0xfe,
0x2b,
0x07,
0xe0,
0xfe,
0x07,
0xf0,
0x39,
0xe8,
0xc0,
0x3f,
0x80,
0xff,
0x1f,
0xc0,
0xbf,
0xe1,
0xb9,
0x06,
0x00,
0x78,
0xf6,
0xff,
0xbf,
0x80,
0xff,
0x00,
0x3f,
0x0f,
0xff,
0xff,
0x8f,
0xe2,
0xfc,
0x03,
0xfc,
0x3c,
0x7f,
0x34,
0x1e,
0xf0,
0xd0,
0xef,
0xe5,
0xf3,
0xff,
0xdf,
0x03,
0x00,
0xee,
0xa3,
0x72,
0x00,
0x83,
0x7e,
0x00,
0x9f,
0xf8,
0xfd,
0xff,
0x07,
0x1f,
0xbe,
0xb1,
0xec,
0x65,
0x97,
0xff,
0x1f,
0x79,
0xf8,
0x07,
0xf8,
0x80,
0xc4,
0x97,
0x01,
0x00,
0xff,
0x81,
0x7f,
0x7f,
0xc3,
0x3f,
0x80,
0x01,
0xfc,
0x07,
0xfe,
0xfe,
0x0d,
0xff,
0x00,
0x07,
0xf0,
0x1f,
0xf8,
0xf8,
0x37,
0xfc,
0x03,
0x00,
0xc0,
0xff,
0xf7,
0x3f,
0x80,
0xff,
0xc0,
0xc0,
0xbf,
0xe1,
0x1f,
0xff,
0x00,
0xfe,
0x03,
0x00,
0xff,
0x86,
0x7f,
0xfc,
0x03,
0xf8,
0x0f,
0x01,
0xfc,
0x1b,
0xfe,
0x7b,
0x00,
0xe0,
0xff,
0xe0,
0x1f,
0xc0,
0x7f,
0x0f,
0xe0,
0xdf,
0xf0,
0x81,
0x7f,
0x00,
0xff,
0x3f,
0x80,
0x7f,
0xc3,
0x07,
0xfe,
0x01,
0xfc,
0xff,
0x00,
0xfe,
0x0d,
0xff,
0x3d,
0x00,
0xf0,
0x3f,
0xf0,
0x0f,
0xe0,
0xf8,
0x07,
0xf0,
0x6f,
0xff,
0xc0,
0x3f,
0x80,
0xe1,
0x1f,
0xc0,
0xbf,
0xfe,
0x03,
0xff,
0x00,
0x86,
0x7f,
0x00,
0xff,
0xf8,
0xff,
0x1e,
0x00,
0xf0,
0x1f,
0xf8,
0x07,
0x37,
0xfc,
0x03,
0xf8,
0xc0,
0x7f,
0xe0,
0x1f,
0xdf,
0xf0,
0x0f,
0xe0,
0x00,
0xff,
0x81,
0x7f,
0x7f,
0xc3,
0x3f,
0x80,
0x00,
0xfc,
0x7f,
0x0f,
0x03,
0xf8,
0x0f,
0xfc,
0xfc,
0x1b,
0xfe,
0x01,
0x0f,
0xe0,
0x3f,
0xf0,
0xf0,
0x6f,
0xf8,
0x07,
0x3f,
0x80,
0xff,
0xc0,
0xc0,
0xbf,
0xe1,
0x1f,
0x07,
0x00,
0xfe,
0xbf,
0xfe,
0x01,
0xfc,
0x07,
0x00,
0xfe,
0x0d,
0xff,
0xf8,
0x07,
0xf0,
0x1f,
0x03,
0xf8,
0x37,
0xfc,
0xe0,
0x1f,
0xc0,
0x7f,
0x0f,
0xe0,
0xdf,
0xf0,
0xdf,
0x03,
0x00,
0xff,
0x03,
0xff,
0x00,
0xfe,
0x7f,
0x00,
0xff,
0x86,
0x0f,
0xfc,
0x03,
0xf8,
0xfe,
0x01,
0xfc,
0x1b,
0x3f,
0xf0,
0x0f,
0xe0,
0xf8,
0x07,
0xf0,
0x6f,
0xff,
0xef,
0x01,
0x80
}};

/*----------------------------------------------------------------------------------------
 *           P R O T O T Y P E S     O F     L O C A L     F U N C T I O N S
 *----------------------------------------------------------------------------------------
 */

/*----------------------------------------------------------------------------------------
 *                          E X P O R T E D    F U N C T I O N S
 *----------------------------------------------------------------------------------------
 */