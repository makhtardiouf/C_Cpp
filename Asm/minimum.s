/* $Id: minimum.s 20 2008-08-08 09:43:59Z Makhtar $
Find the smallest number in a set of numbers, using
byte sized operations
	
%cx - Holds the index of the current items item
%bx - smallest item found, used as exit value
%ax - Current item

Remember that the instruction "movbl" _copies_ data
Type "echo $?" to see the max val */

.section .data
items:
	/* List of integers; 0 marks the end of the list */
	.int 3, 1, 34, 184, 2, 5

.section .text
.globl _start

_start:
	/* Initialize the index register */
	mov $0, %edi
	
	/* Load the first double bytes of items using indexed addressing mode */
	mov items(,%edi,4), %eax

	mov %eax, %ebx
	call GetMin

.type GetMin, @function
GetMin:
	/* Exit if we've hit the end(e.g. 5) */
	cmp $5, %eax
	je Exit

	/* else increment the pointer and load next value */
	inc %edi
	mov items(,%edi,4), %eax

	/* Restart looping if the current number is
	>= to the smallest recorded so far */
	cmp %ebx, %eax
	jge GetMin

	/* else, record the new min value and restart looping */
	mov %eax, %ebx
	jmp GetMin

Exit:
	mov $1, %eax
	int $0x80
