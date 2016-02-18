/* $Id: maximum2.s 18 2008-07-06 09:18:48Z Makhtar $
Find the maximum number in a set of numbers
%edi - Holds the index of the current items item
%ebx - Largest items item found, used as exit value
%eax - Current items item

Remember that the instruction "movl" _copies_ data
Type "echo $?" to see the max val */

.section .data
msg:
	.ascii "The maximum is: %d\0"

items:
	/* 0 marks the end of the list */
	.int 3, 62, 34, 129, 57, 0

.section .text
.globl _start

_start:
	/* Initialize the index register */
	mov $0, %edi

	/* Load the first byte of items using indexed addressing mode*/
	mov items(,%edi,4), %eax

	mov %eax, %ebx
	call GetMax

	addl  $8, %esp
	pushl %ebx
	pushl $msg
	call printf

	mov $1, %eax
	int $0x80


.type GetMax, @function
GetMax:
	/* Return after hitting the end(e.g. 0) */
	cmp $0, %eax
	je Return

	/* else increment the pointer and load next value */
	inc %edi
	mov items(,%edi,4), %eax

	/* Restart looping if the current number is <= to the biggest recorded so far */
	cmp %ebx, %eax
	jle GetMax

	/* else, record the new max value and restart looping */
	mov %eax, %ebx
	jmp GetMax

Return:
	ret
