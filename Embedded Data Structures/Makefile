
include sources.mk

TARGET = C1M3
PLATFORM=MSP432
CPU=cortex-m4
ARCH=thumb
SPECS=nosys.specs
LINKER_FILE = msp432p401r.lds

CC=arm-none-eabi-gcc
CFLAGS = -save-temps -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wall -Werror -g -O0 -std=c99
CPPFLAGS = -MD
LDFLAGS = -Xlinker -Map=$(TARGET).map -T $(LINKER_FILE)

%.i : $(SOURCES)
	$(CC) -E $(CPPFLAGS) $(CFLAGS) -o $@ -D$(PLATFORM) $<

%.o : $(SOURCES)
	$(CC) -c $(CPPFLAGS) $(CFLAGS) -o $@ -D$(PLATFORM) $<

%.asm : $(SOURCES)
	$(CC) -S $(CPPFLAGS) $(CFLAGS) -o $@ -D$(PLATFORM) $<

.PHONY: compile-all
compile-all:
	$(CC) -c $(CPPFLAGS) $(CFLAGS) -D$(PLATFORM) $(SOURCES)

.PHONY: build
build: $(TARGET).out

$(TARGET).out: compile-all
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $(TARGET).out $(INCLUDES) -D$(PLATFORM) $(SOURCES)

.PHONY: nm
nm:
	rm -f nmOutput.txt
	nm -C -l -n -S -s --special-syms --synthetic C1M3.out > nmOutput.txt

.PHONY: dump
dump:
	make main.asm
	make misc.asm
	rm -f mainDumpOutput.txt
	rm -f miscDumpOutput.txt
	cat main.asm > mainDumpOutput.txt
	cat misc.asm > miscDumpOutput.txt

.PHONY: clean
clean:
	rm -f *.out *.s *.gch *.map *.i *.asm *.o *.d nmOutput.txt mainDumpOutput.txt miscDumpOutput.txt

#Helps debug make file
#E.g type "make print-TARGET"
print-%  : ; @echo $* = $($*)
