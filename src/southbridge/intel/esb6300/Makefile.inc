ifeq ($(CONFIG_SOUTHBRIDGE_INTEL_ESB6300),y)

ramstage-y += esb6300.c
ramstage-y += reset.c
ramstage-y += uhci.c
ramstage-y += lpc.c
ramstage-y += ide.c
ramstage-y += sata.c
ramstage-y += ehci.c
ramstage-y += smbus.c
ramstage-y += pci.c
ramstage-y += pic.c
ramstage-y += bridge1c.c
ramstage-y += ac97.c

endif