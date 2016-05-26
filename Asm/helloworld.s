
/* $Id: helloworld.s 18 2008-07-06 09:18:48Z Makhtar $ 
	build with: make helloworld */

.section .data
result:
	.ascii "Hello, World\n\0"
	
.section .text
	
.globl _start
_start:
	pushl $result
	call printf

	pushl $0
	call exit
#	movl $1, %eax
#	int $0x80
	