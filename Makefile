CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -o0
LDFLAGS= -nostdlib -T st_ls.ld -Wl,-Map=main.map

all:main.o st_startup.o main.elf

main.o:main.c
	$(CC) $(CFLAGS) -o $@ $^

st_startup.o:st_startup.c
	$(CC) $(CFLAGS) -o $@ $^

main.elf: main.o st_startup.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -rf *.o *.elf