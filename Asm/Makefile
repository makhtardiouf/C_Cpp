
# Makefile build code written in assembler
# Makhtar Diouf 
ASM1=as
ASM2=yasm -f elf -g stabs
LINKER=ld
FLAGS =-g --warn
#--gstabs
LDFLAGS=-dynamic-linker /lib64/ld-linux-x86-64.so.2 -lc 

.s :
	$(ASM1) $(FLAGS) $< -o $@.o
	$(LINKER) $(LDFLAGS) $@.o -o $@-as
	@rm $@.o

.asm:
	$(ASM2) $< -o $@.o
	gcc -Wall -o $@-yasm -L. $@.o asm_driver.c
	@rm $@.o

toupper: toupper.s linux32.s
	$(ASM1) $(FLAGS) toupper.s -o $@.o
	$(ASM1) $(FLAGS) linux32.s -o linux.o
	$(LINKER) $(LDFLAGS) $@.o linux.o -o $@
	@rm *.o

toupper64: toupper64.s linux64.o	
	$(ASM1) $(FLAGS) $@.s -o $@.o
	$(LINKER) $@.o linux64.o -o $@
	@rm $@.o

copy64: copy64.s linux64.o
	$(ASM1) $(FLAGS) $@.s -o $@.o
	$(LINKER) $@.o linux64.o -o $@
	@rm $@.o

linux64.o: linux64.s
	$(ASM1) $(FLAGS) linux64.s -o linux64.o


# helloworld: helloworld.asm asm_driver.o
# 	$(ASM2) -l helloworld.raw $<
# 	$(ASM2) $< -o $@.o
# 	gcc -Wall -L. -o $@ $@.o asm_driver.c
# 	make finish
