
# Makefile to assemble and like 
# code written in assembler

ASSEMBLER1=as
ASSEMBLER2=yasm -f elf -g stabs
LINKER=ld
FLAGS =-g --warn
#--gstabs
LDFLAGS=-dynamic-linker /lib64/ld-linux-x86-64.so.2 -lc 
#/lib/ld-linux.so.2 -lc
#LDFLAGS=-lc

# helloworld: helloworld.asm asm_driver.o
# 	$(ASSEMBLER2) -l helloworld.raw $<
# 	$(ASSEMBLER2) $< -o $@.o
# 	gcc -Wall -L. -o $@ $@.o asm_driver.c
# 	make finish

# helloworld: helloworld.s
# 	$(ASSEMBLER1) -o $@.o
# 	$(LINKER) -lc -o $@
# 	@rm $@.o

# exit: exit.s
# 	$(ASSEMBLER1) $(FLAGS) $< -o $@.o
# 	$(LINKER) $@.o -o $@
# 	rm $@.o

toupper: toupper.s linux.s
	$(ASSEMBLER1) $(FLAGS) toupper.s -o $@.o
	$(ASSEMBLER1) $(FLAGS) linux.s -o linux.o
	$(LINKER) $@.o linux.o -o $@

toupper64: toupper64.s linux64.o
	@rm $@ $@.o
	$(ASSEMBLER1) $(FLAGS) $@.s -o $@.o
	$(LINKER) $@.o linux64.o -o $@

copy64: copy64.s linux64.o
	@rm $@ $@.o
	$(ASSEMBLER1) $(FLAGS) $@.s -o $@.o
	$(LINKER) $@.o linux64.o -o $@

linux64.o: linux64.s
	$(ASSEMBLER1) $(FLAGS) linux64.s -o linux64.o

.s :
#	@rm $@
	$(ASSEMBLER1) $(FLAGS) $< -o $@.o
	$(LINKER) $(LDFLAGS) $@.o -o $@-as
	@rm $@.o

.asm:
	$(ASSEMBLER2) $< -o $@.o
	gcc -Wall -o $@-yasm -L. $@.o asm_driver.c
	@rm $@.o
