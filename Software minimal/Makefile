SDCC ?= sdcc
#STC15F104W
STCCODESIZE ?= 4089
SDCCLOPTS ?= --code-size $(STCCODESIZE) --iram-size 128 --xram-size 0 --stack-auto  --model-small --out-fmt-ihx
#--xram-size <Value> Causes the linker to check if the external ram usage is within limits of the given value.
#--stack-loc 0x44
#--data-loc 0x20
SDCCREV ?= -DSTC15F104W
FLASHFILE ?= main.hex
SYSCLK ?= 11057
CFLAGS ?=  

SRC = src/main.c  
OBJ=  build/main.rel 
	
all: main.hex

build/main.rel: src/main.c src/stc8.h makefile
	$(SDCC)  -c $< -o $@ $(SDCCCOPTS)


main.hex: $(OBJ)
	$(SDCC) $^ -o main.hex $(SDCCLOPTS) $(SDCCREV) $(CFLAGS)
	@ tail -n 5 build/main.mem | head -n 2
	@ tail -n 1 build/main.mem 


eeprom:
	sed -ne '/:..1/ { s/1/0/2; p }' main.hex > eeprom.hex

flash:
	$(STCGAL) -p $(STCGALPORT) -P $(STCGALPROT) -t $(SYSCLK) $(STCGALOPTS) $(FLASHFILE)

clean:
	rm -f build/*

cpp: SDCCOPTS+=-E
cpp: main
