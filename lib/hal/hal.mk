ifeq ($(HALCONFDIR),)
	ifeq ($(CONFDIR),)
		HALCONFDIR = .
	else
		HALCONFDIR := $(CONFDIR)
	endif
endif

HALCONF := $(strip $(shell cat $(HALCONFDIR)/halconf.h | egrep -e "\#define"))

ifneq ($(findstring HAL_USE_PAL TRUE,$(HALCONF)),)
	SOURCES += $(HAL_PATH)/src/pal.c
endif

ifneq ($(findstring HAL_USE_SPI TRUE,$(HALCONF)),)
	SOURCES += $(HAL_PATH)/src/spi.c
endif

ifneq ($(findstring HAL_USE_USART TRUE,$(HALCONF)),)
	SOURCES += $(HAL_PATH)/src/usart.c
endif

INCLUDES += -I$(HAL_PATH)/include

INCLUDES += -I$(HALCONFDIR)

