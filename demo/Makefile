# Define o nome do projeto.
PROJECT = avr-lib-demo

# Define as configurações da placa.
BOARD_PATH = board
include $(BOARD_PATH)/board.mk

# Define as configuações da biblioteca auxiliar.
LIB_PATH = ../lib
include $(LIB_PATH)/lib.mk

# Define os fontes do projeto.
SOURCES += src/main.c

# Diretórios adicionais de inclusão.
INCLUDES += -Isrc

# Modelo do microcontrolador.
#   Arduino Uno  = atmega328p
#   Arduino Mega = atmega2560
MCU = atmega2560

# Frequência do cristal.
F_CPU = 16000000UL

# Opções do programador.
#   PG      = arduino (Arduino Uno) | wiring (Arduino Mega/ADK)
#   PG_PORT = porta de comunicação
#   PG_BAUD = velocidade de gravação
PG      = avrispmkii
PG_PORT = /dev/ttyUSB0
PG_BAUD = 115200
PG_CONFIG =

# Outras configurações.
CC      = avr-gcc
OBJCOPY = avr-objcopy
SIZE	= avr-size
CP      = cp
DEL     = rm -f
GIT     = git

BUILD_DATE	= \""`date --rfc-3339=seconds`"\"
BUILD_VERSION	= \"`$(GIT) describe --dirty --always  --tags`\"

CFLAGS	+= -DBUILD_DATE=$(BUILD_DATE) -DBUILD_VERSION=$(BUILD_VERSION)
CFLAGS  += -O1 -Wall -Wextra -g -std=gnu99 -DF_CPU=$(F_CPU)
ARCH    = -mmcu=$(MCU)

OBJECTS = $(SOURCES:.c=.o)
CFLAGS 	+= $(INCLUDES)

all: $(PROJECT).hex

%.hex: %.elf
	$(OBJCOPY) -R .eeprom -j .text -j .data -O ihex $< $@

$(PROJECT).elf: $(OBJECTS)
	$(CC) $(CFLAGS) $(ARCH) $^ -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $(ARCH) -o $@ $(CCFLAGS) $<

clean:
	$(DEL) $(OBJECTS)
	find . -type f \( -name '*.o' -o -name '*.elf' -o -name '*.hex' \) -exec $(DEL) {} +

size: $(PROJECT).elf
	$(SIZE) -C --mcu=$(MCU) $(PROJECT).elf

flash: $(PROJECT).hex
	avrdude -c $(PG) $(PG_CONFIG) -p $(MCU) -U flash:w:$<

erase: $(PROJECT).hex
	avrdude -c $(PG) $(PG_CONFIG) -p $(MCU) -e

archive:
	$(GIT) archive --prefix=$(PROJECT)/ -o $(PROJECT)-$(COMMIT).tar.gz HEAD

fuse:
	avrdude -D -c $(PG) $(PG_CONFIG) -p $(MCU) -U lfuse:w:0xff:m -U hfuse:w:0xD9:m -U efuse:w:0xff:m

