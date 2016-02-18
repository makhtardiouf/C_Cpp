/* 64 bit version
	PURPOSE - Given a number, this program computes the
	          factorial.  For example, the factorial of
	          4 is 4 * 3 * 2 * 1, or 24

	This program shows how to call a function recursively. 
*/
	.section .data

	.section .text

	.globl _start
	.globl factorial /* unneeded unless we want to share
	                  this function among other programs */

_start:
	push $5          /* The number we want a factorial of */
	call  factorial
	
	add  $8, %rsp    /* Scrubs the parameter that was pushed on the stack */
	mov  %rax, %rbx  /* The answer is in %rax,
			   but we want it in %rbx to send it as our exit status */
	mov  $1, %rax    /*call the kernel exit function */
	int   $0x80


/* Definition of the factorial function */
	.type factorial,@function
factorial:
	push %rbp        /* standard function stuff - we have to 
	                   restore %rbp to its prior state before returning */
	
	mov  %rsp, %rbp  /* We do not want to modify the stack pointer,
                            so we use %rbp. */

	mov  16(%rbp), %rax  /* Base pointer addressing
                              8(%rbp) holds the return address(pushed by "call"), 
                              and 16(%rbp) holds the first parameter */
	
	cmp  $1, %rax       /* Check for the base case */
	je end_factorial
	/* ELSE */
	dec  %rax            /* otherwise, decrement it */
	push  %rax           /* and pass it as parameter to "factorial" */
	call  factorial
	/* Only rsp and rbp retain their values after a function call */
	mov  16(%rbp), %rbx /* %rax has the return value, so we 
	                    /* reload our parameter into %rbx */
	imul %rbx, %rax     /* multiply that by the result of the
	                     last call to factorial (in %rax)
	                     the answer is stored in %rax, which 
	                     is good since that is where return values go. */
	
end_factorial:
/*standard function return stuff - 
we have to restore %rbp and %rsp to where
they were before the function started 
(Reactivate the previous stack frame, opposite of the beginning of factorial:) */
	mov  %rbp, %rsp    
	pop  %rbp          	
/* return from the function, pops the return value,
 then goes back to the point following the last "call factorial" */
        ret
