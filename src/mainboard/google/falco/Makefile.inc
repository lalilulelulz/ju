##
## This file is part of the coreboot project.
##
## Copyright (C) 2012 Google Inc.
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; version 2 of the License.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program; if not, write to the Free Software
## Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
##

ramstage-$(CONFIG_EC_GOOGLE_CHROMEEC) += ec.c

romstage-$(CONFIG_CHROMEOS) += chromeos.c
ramstage-$(CONFIG_CHROMEOS) += chromeos.c
ramstage-$(CONFIG_MAINBOARD_DO_NATIVE_VGA_INIT) += ../slippy/gma.c ../slippy/i915io.c

smm-$(CONFIG_HAVE_SMI_HANDLER) += smihandler.c

## DIMM SPD for on-board memory
SPD_BIN = $(obj)/spd.bin

# Order of names in SPD_SOURCES is important!
SPD_SOURCES  = Micron_4KTF25664HZ     # 4GB / CH0 + CH1 (RAM_ID=000)
SPD_SOURCES += Hynix_HMT425S6AFR6A    # 4GB / CH0 + CH1 (RAM_ID=001)
SPD_SOURCES += Elpida_EDJ4216EFBG     # 4GB / CH0 + CH1 (RAM_ID=010)
SPD_SOURCES += Micron_4KTF25664HZ     # 2GB / CH0 only  (RAM_ID=011)
SPD_SOURCES += Hynix_HMT425S6AFR6A    # 2GB / CH0 only  (RAM_ID=100)
SPD_SOURCES += Elpida_EDJ4216EFBG     # 2GB / CH0 only  (RAM_ID=101)
SPD_SOURCES += Samsung_M471B5674QH0   # 4GB / CH0 + CH1 (RAM_ID=110)
SPD_SOURCES += Samsung_M471B5674QH0   # 2GB / CH0 only  (RAM_ID=111)

SPD_DEPS := $(foreach f, $(SPD_SOURCES), src/mainboard/$(MAINBOARDDIR)/$(f).spd.hex)

# Include spd rom data
$(SPD_BIN): $(SPD_DEPS)
	for f in $+; \
	  do for c in $$(cat $$f | grep -v ^#); \
	    do echo -e -n "\\x$$c"; \
	  done; \
	done > $@

cbfs-files-y += spd.bin
spd.bin-file := $(SPD_BIN)
spd.bin-type := 0xab
spd.bin-position := 0xfffec000
