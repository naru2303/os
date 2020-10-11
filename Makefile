# Source directories seperate by space
# Ex: ./ src1/ src2
SRCDIR = ./ arch/arm/stm32l496zg/ entry/ lib/ drivers/gpio/
# Directory where object files will go
OBJDIR = build/
# Directory where binary files will go
BINDIR = build/
# Map file directory
MAPDIR = build/
# Include directory
INCDIR = ./ include/os-include/
# Linker script directory
LINKDIR = arch/arm/stm32l496zg
# Name of output file
TARGET = main.elf
# Compiler
CC=arm-none-eabi-gcc
# Processor
MACH=cortex-m4
#Get list of source files
SRC = $(wildcard $(addsuffix *.c,$(SRCDIR)))
# Generate list of object files
OBJ = $(addprefix $(OBJDIR), $(patsubst %.c, %.o, $(notdir $(SRC))))
VPATH = $(SRCDIR)

# Compilation flags
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -g -o0

LDFLAGS= -nostdlib -g -T $(LINKDIR)/st_ls.ld -Wl,-Map=$(MAPDIR)/main.map

$(OBJDIR)%.o : %.c
	@echo Compiling $< in $@...
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(CFLAGS) $(addprefix -I, $(INCDIR)) -c -o $@ $^

$(TARGET) : $(OBJ)
	@echo Linking...
	@mkdir -p $(BINDIR)
	@$(CC) $(LDFLAGS) -o $(BINDIR)$@ $(OBJ)

clean:
	@$(RM) -r $(OBJDIR)
	@$(RM) -r $(BINDIR)
