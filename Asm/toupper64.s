/*
$Id: toupper.s 10 2007-12-06 13:45:15Z Makhtar $
Convert input file to an output file with all letters in upper case form
*/

    .include "linux64.s"

	.section .data

	.equ NARGS, 2		/* number of args */

	.section .bss

	/* The buffer should never exceed 16,000
       similar to char* buf[500]  */
	.equ BUF_SIZE, 500
	.lcomm BUF_PTR, BUF_SIZE

	.section .text

	/* stack positions */
	.equ ST_SIZE_RESERVE, 16
	.equ ST_FD_IN, 0
	.equ ST_FD_OUT, 8
/* on x86-64 linux automatically store command line args
 at the following locations

on x86-32 argc@8(%esp) argv[0]@12(%esp) argv[1]@16(%esp) ...
*/
	.equ ST_ARGC, 16 	/* number of args at offset 0 */
	.equ ST_ARGV_0, 24	/* name of program */
	.equ ST_ARGV_1, 32	/* input file name */
	.equ ST_ARGV_2, 40	/* output file name */

	.globl _start

_start:
	/* init */
	sub $ST_SIZE_RESERVE, %rsp  /* alloc space for file descriptors on the stack */
	mov %rsp, %rbp		        /* save the stack pointer */

open_files:
	/* open input file */
open_fd_in:
	mov ST_ARGV_1(%rbp), %rdi    /* input filename(direct addressing mode) */
	mov $READ_OPTS, %rsi         /* read only flag similar to xor %rsi, %rsi */
	mov $0666, %rdx              /* MODE, does not really matter here */
	mov $SYS_OPEN, %rax	         /* open syscall. We could use "call open" and link
                                    with the c lib instead */
	syscall

	/* save the given file descriptor */
store_fd_in:
	mov %rax, ST_FD_IN(%rbp)

	/* open output file */
open_fd_out:
	mov ST_ARGV_2(%rbp), %rdi
	mov $WRITE_OPTS, %rsi
	mov $0666, %rdx
	mov $SYS_OPEN, %rax
	syscall

store_fd_out:
	mov %rax, ST_FD_OUT(%rbp)

	/* Begin main loop */
start_read:
	/* read in a block */
	mov ST_FD_IN(%rbp), %rdi
	mov $BUF_PTR, %rsi
	mov $BUF_SIZE, %rdx
	mov $SYS_READ, %rax
	syscall

	/* now that we have the size of buffer read in %rax, check for EOF */
	cmp $EOF, %rax
	jle  stop_read		   /* jump if reached or on error */

	/* else continue */
continue_read:
	push $BUF_PTR
	push %rax           /* size of the data that has been read */
	call to_upper
	pop  %rax           /* get the size back */
    /* pop  %rbx */
	add  $16, %rsp      /* restore the sp */

	/* write to output */
	mov ST_FD_OUT(%rbp), %rdi
	mov $BUF_PTR, %rsi
    mov %rax, %rdx
	mov $SYS_WRITE, %rax
	syscall

	/* continue the loop */
	jmp start_read

	/* close the files, without error checking; then exit */
stop_read:
	mov ST_FD_OUT(%rbp), %rdi
	mov $SYS_CLOSE, %rax
	syscall

	mov ST_FD_IN(%rbp), %rdi
	mov $SYS_CLOSE, %rax
	syscall

	/* Exit */
	mov $0, %rdi
	mov $SYS_EXIT, %rax
	syscall


	/* FUNCTION to_upper
	 Get the location of the buffer to convert
	 as first arg, and the length of that buffer as second arg
	 overwrite the buffer with the upper-casified version

	 %rax - beginning of buffer
	 %rbx - length of buffer
	 %rdi - current buffer offset
	 %cl  - current byte being examined (1st part of %rcx)
         */
	.equ LOWERCASE_A, 'a'
	.equ LOWERCASE_Z, 'z'
	/* conversion trick */
	.equ UPPER_CONVERSION, 'A' - 'a'

	/* Function stack stuff */
	.equ ST_BUF_PTR, 8     /* Pointer to the buffer */
	.equ ST_BUF_SIZE, 16

to_upper:
	push %rbp
	mov  %rsp, %rbp
    /*enter */

	mov ST_BUF_PTR(%rbp), %rdi
	mov ST_BUF_SIZE(%rbp), %rsi

	/* if a buff with zero length was given to us, leave */
	cmp $0, %rsi
	je stop_conversion

	mov $0, %rdx

start_conversion:
    xor %rcx, %rcx /* clear rcx (contains %cl) */
	/* get the current byte */
	movb (%rdi,%rdx,1), %cl

	/* go to the next byte unless it is between 'a' and 'z' */
	cmpb $LOWERCASE_A, %cl
	jl   next_byte
	cmpb $LOWERCASE_Z, %cl
	jg   next_byte

	/* otherwise convert the byte to uppercase */
	addb $UPPER_CONVERSION, %cl
	/* and write it back */
	movb %cl, (%rdi,%rdx,1)

next_byte:
	inc %rdx             /* next byte */
	cmp %rdx, %rsi		 /* continue unless we've reached the end */
	jne start_conversion

stop_conversion:
	/* leave without returning a value */
	/* mov %rbp, %rsp
	pop %rbp */
    leave
	ret
