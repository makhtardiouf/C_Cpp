/*
$Id: toupper.s 10 2007-12-06 13:45:15Z Makhtar $
ASM demo: copy the contents a file to another file

Usage: ./copy64 test1.txt test2.txt
*/

    .include "linux64.s"

	.section .data

	.equ NARGS, 2		/* number of args */

	.section .bss

	/* The buffer should never exceed 16,000
       similar to char* buf[500]  */
	.equ BUF_SIZE, 500
	.lcomm BUF_PTR, BUF_SIZE /* reserve BUF_SIZE bytes for the symbol BUF_PTR */

	.section .text

	/* stack positions */
	.equ ST_SIZE_RESERVE, 16
	.equ ST_FD_IN, 0
	.equ ST_FD_OUT, 8
	.equ ST_ARGC, 16 	/* number of args at offset 0 */
	.equ ST_ARGV_0, 24	/* name of program */
	.equ ST_ARGV_1, 32	/* input file name */
	.equ ST_ARGV_2, 40	/* output file name */

	.globl _start

_start:
	sub $ST_SIZE_RESERVE, %rsp  /* alloc space for file descriptors on the stack */
	mov %rsp, %rbp		        /* save the stack pointer */

	/* open input file */
open_fd_in:
	mov ST_ARGV_1(%rbp), %rdi    /* input filename(direct addressing mode) */
	mov $READ_OPTS, %rsi         /* read only flag similar to xor %rsi, %rsi */
	mov $0666, %rdx              /* MODE, does not really matter here */
	mov $SYS_OPEN, %rax	         /* open syscall. We could use "call open" and link
                                    with the c lib instead */
	syscall

	/* save the given file descriptor */
	mov %rax, ST_FD_IN(%rbp)

	/* open output file */
open_fd_out:
	mov ST_ARGV_2(%rbp), %rdi
	mov $WRITE_OPTS, %rsi
	mov $0666, %rdx
	mov $SYS_OPEN, %rax
	syscall

	mov %rax, ST_FD_OUT(%rbp)

	/* Start processing */
start_read:
	/* read in a block */
	mov ST_FD_IN(%rbp), %rdi
	mov $BUF_PTR, %rsi
	mov $BUF_SIZE, %rdx
	mov $SYS_READ, %rax
	syscall

	/* check the result stored in %rax, to catch EOF */
	cmp $EOF, %rax
	jle  stop_read

	/* write to output */
	mov ST_FD_OUT(%rbp), %rdi
	mov $BUF_PTR, %rsi
    mov %rax, %rdx
	mov $SYS_WRITE, %rax
	syscall

	/* loop */
	jmp start_read

	/* close the files, then exit */
stop_read:
	mov ST_FD_OUT(%rbp), %rdi
	mov $SYS_CLOSE, %rax
	syscall

	mov ST_FD_IN(%rbp), %rdi
	mov $SYS_CLOSE, %rax
	syscall

	/* Exit */
	xor %rdi, %rdi         /* set the exit value to 0 */
	mov $SYS_EXIT, %rax
	syscall
