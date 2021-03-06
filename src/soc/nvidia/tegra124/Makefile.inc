CBOOTIMAGE = cbootimage

bootblock-y += bootblock.c
bootblock-y += bootblock_asm.S
bootblock-y += cbfs.c
bootblock-y += clock.c
bootblock-y += monotonic_timer.c
bootblock-y += ../tegra/gpio.c
bootblock-y += ../tegra/pingroup.c
bootblock-y += ../tegra/pinmux.c
bootblock-y += timer.c
ifeq ($(CONFIG_BOOTBLOCK_CONSOLE),y)
bootblock-$(CONFIG_CONSOLE_SERIAL_UART) += uart.c
endif

romstage-y += cbfs.c
romstage-y += monotonic_timer.c
romstage-y += timer.c
ifeq ($(CONFIG_EARLY_CONSOLE),y)
romstage-$(CONFIG_CONSOLE_SERIAL_UART) += uart.c
endif

ramstage-y += cbfs.c
ramstage-y += monotonic_timer.c
ramstage-y += timer.c
ramstage-$(CONFIG_CONSOLE_SERIAL_UART) += uart.c

INCLUDES += -Isrc/soc/nvidia/tegra124/include/

# We want to grab the bootblock right before it goes into the image and wrap
# it inside a BCT, but ideally we would do that without making special, one
# use modifications to the main ARM Makefile. We do this in two ways. First,
# we copy bootblock.elf to bootblock.raw.elf and allow the %.bin: %.elf
# template rule to turn it into bootblock.raw.bin. This makes sure whatever
# processing is supposed to happen to turn an .elf into a .bin happens.
#
# Second, we add our own rule for creating bootblock.bin from
# bootblock.raw.bin which displaces the template rule. When other rules that
# package up the image pull in bootblock.bin, it will be this wrapped version
# instead of the raw bootblock.

$(objcbfs)/bootblock.raw.elf: $(objcbfs)/bootblock.elf
	cp $< $@

$(obj)/generated/bct.bin: $(obj)/generated/bct.cfg
	@printf "    CBOOTIMAGE $(subst $(obj)/,,$(@))\n"
	$(CBOOTIMAGE) -gbct --soc tegra124 $< $@

BCT_BIN = $(obj)/generated/bct.bin
BCT_WRAPPER = $(obj)/generated/bct.wrapper
$(objcbfs)/bootblock.bin: $(objcbfs)/bootblock.raw.bin $(BCT_BIN)
	echo "Version    = 1;" > $(BCT_WRAPPER)
	echo "Redundancy = 1;" >> $(BCT_WRAPPER)
	echo "Bctfile    = $(BCT_BIN);" >> $(BCT_WRAPPER)
	echo "BootLoader = $<,$(CONFIG_BOOTBLOCK_BASE),$(CONFIG_BOOTBLOCK_BASE),Complete;" >> $(BCT_WRAPPER)
	@printf "    CBOOTIMAGE $(subst $(obj)/,,$(@))\n"
	$(CBOOTIMAGE) $(BCT_WRAPPER) $@
