
# Simple program that exits and returns a status
# code back to the Linux Kernel
/* ATT syntax */

.section .data		# used for memory allocation
			# we only use regs here so... no need for this

.section .text
	
.globl _start

_start:
	
	movl $1, %eax    # system call number for exiting a Linux program

	movl $0, %ebx   # store the status number

	int $0x80	 # interrupt this program and wake up 
			 #  the kernel to run the exit command
