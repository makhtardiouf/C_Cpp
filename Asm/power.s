/* $Id: power.s 10 2007-12-06 13:45:15Z Makhtar $
Illustrate how functions work by computing the value of 2^3 + 5^2 */

.section .data
msg:
	.ascii "The result is %d\n\0"

.section .text
.globl _start
_start:
	pushl $3
	pushl $2
	call  power
	addl  $8, %esp	/* move z stack pointer back */
	pushl %eax		/* save the 1st answer */

	pushl $2
	pushl $5
	call  power
	addl  $8, %esp

/* Store the (1st) answer that was saved onto the stack to %ebx */
	popl  %ebx
/*add the two answers, knowing that z second is already in %eax*/
	addl  %eax, %ebx
/*  Print the result to stdout */
	pushl %ebx
	pushl $msg
	call  printf

	movl  $1,   %eax
	int   $0x80


/* Declaration and definition of the function power
%ebx hold the base number
%ecx hold the power
-4(%ebp) hold the current result */
.type power, @function
power:
	pushl %ebp		 /*save old base pointer(bp)*/
	movl  %esp, %ebp	/* copy the stack pointer(sp) to the (old) bp*/
	subl  $4, %esp	 /*alloc mem for local storage*/

	movl  8(%ebp), %ebx	 	/*copy 1st arg to %ebx*/
	movl  12(%ebp), %ecx	 /*copy 2nd arg(the power) to %ecx*/
	movl  %ebx, -4(%ebp)	 /*store current result*/

power_loop_start:
	cmpl  $1, %ecx
	je    end_power

	movl  -4(%ebp), %eax	 /*store the current result into %eax*/
	imull %ebx, %eax	 	/*multiply curr result by base number*/

	movl  %eax, -4(%ebp)	 /*store curr result*/
	decl  %ecx
	jmp   power_loop_start

end_power:
	movl  -4(%ebp), %eax	 /*copy the result to %eax*/
	movl  %ebp, %esp	 /*restore the stack pointer*/
	popl  %ebp		 	/*restore the base pointer*/
	ret
