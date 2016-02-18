/* $Id: maximum.s 18 2008-07-06 09:18:48Z Makhtar $
Find the maximum number in a set of numbers
%rdi - Holds the index of the current items item
%rbx - Largest data item found, used as exit value
%rax - Current data item
*/

.section .data
items:
	/* List of integers; 0 marks the end of the list
	ints use just half of the size of regs (2 bytes)
	*/
	.int 3, 62, 34, 184, 57, 0

msg:
	.string "Identifying the maximum value... type echo $?"
	
.section .text
.globl _start

_start:
      /*  push %rbp
        mov %rsp, %rbp
*/
	mov $msg, %edi
	call puts
        add $8, %rsp

	/* Initialize the index register */
	mov $0, %rdi

        /* Load the first byte of items using indexed addressing mode */
	mov items(,%rdi,8), %rax

	mov %rax, %rbx
	call GetMax

.type GetMax, @function
GetMax:
	/* Exit if we've hit the end(e.g. 0) */
	cmp $0, %rax
	je Exit

	/* else increment the pointer and load next value */
	inc %rdi
	mov items(,%rdi,8), %rax

	/* Restart looping if the current number is
	<= to the biggest recorded so far */
	cmp %rbx, %rax
	jle GetMax

	/* else, record the new max value and restart looping */
	mov %rax, %rbx
	jmp GetMax

Exit:
	mov $1, %rax
	int $0x80
