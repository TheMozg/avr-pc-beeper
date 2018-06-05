.SUFFIXES:

TARGET   = beeper
MCU      = attiny85
DUDE_MCU = attiny85
PROGR    = avrisp
PORT     = /dev/ttyS0

CC       = avr-gcc
OBJCOPY  = avr-objcopy
DUDE     = avrdude

CFLAGS   = -Wall -Werror -Os -DF_CPU=8000000UL
PFLAGS   = -b 19200

SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.c)
HEADERS  := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

.PHONY: all
all: $(BINDIR)/$(TARGET).hex

$(BINDIR)/$(TARGET).hex: $(BINDIR)/$(TARGET).elf $(MAKEFILE_LIST)
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

$(BINDIR)/$(TARGET).elf: $(OBJECTS) $(MAKEFILE_LIST) | $(BINDIR)
	$(CC) -mmcu=$(MCU) $(CFLAGS) -o $@ $(OBJECTS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) $(MAKEFILE_LIST) | $(OBJDIR)
	$(CC) -mmcu=$(MCU) $(CFLAGS) -o $@ -c $<

$(OBJDIR) $(BINDIR):
	mkdir $@

.PHONY: flash
flash: $(BINDIR)/$(TARGET).hex
	$(DUDE) -c $(PROGR) -p $(DUDE_MCU) -P $(PORT) $(PFLAGS) -U flash:w:$<

.PHONY: clean
clean:
	rm -rf $(OBJDIR)
	rm -rf $(BINDIR)
