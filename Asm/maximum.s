/* $Id: maximum.s 18 2008-07-06 09:18:48Z Makhtar $
Find the maximum number in a set of numbers
%edi - Holds the index of the current items item
%ebx - Largest data item found, used as exit value
%eax - Current data item

Remember that the instruction "movl" _copies_ data
Type "echo $?" to see the max val */

.section .data
items:
	/* List of integers; 0 marks the end of the list
	ints use just half of the size of regs (2 bytes)
	*/
	.int 3, 62, 34, 184, 57, 0

.section .text
.globl _start

_start:
	/* Initialize the index register */
	mov $0, %edi

	/* Load the first byte of items using indexed addressing mode */
	mov items(,%edi,4), %eax

	mov %eax, %ebx
	call GetMax

.type GetMax, @function
GetMax:
	/* Exit if we've hit the end(e.g. 0) */
	cmp $0, %eax
	je Exit

	/* else increment the pointer and load next value */
	inc %edi
	mov items(,%edi,4), %eax

	/* Restart looping if the current number is
	<= to the biggest recorded so far */
	cmp %ebx, %eax
	jle GetMax

	/* else, record the new max value and restart looping */
	mov %eax, %ebx
	jmp GetMax

Exit:
	mov $1, %eax
	int $0x80
