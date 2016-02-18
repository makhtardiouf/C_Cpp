	.file	"toupper.c"
	.section	.rodata
.LC0:
	.string	"argc @ %x\n"
.LC1:
	.string	"argv[0] @ %x\n"
.LC2:
	.string	"argv[1] @ %x\n"
.LC3:
	.string	"argv[2] @ %x\n"
.LC4:
	.string	"fdin @ %x\n"
.LC5:
	.string	"fdout @ %x\n"
	.text
.globl main
	.type	main, @function
main:
.LFB2:
	pushq	%rbp
.LCFI0:
	movq	%rsp, %rbp
.LCFI1:
	subq	$544, %rsp
.LCFI2:
	movl	%edi, -532(%rbp)
	movq	%rsi, -544(%rbp)
	movq	stderr(%rip), %rdi
	leaq	-532(%rbp), %rdx
	movl	$.LC0, %esi
	movl	$0, %eax
	call	fprintf
	movq	stderr(%rip), %rdi
	movq	-544(%rbp), %rdx
	movl	$.LC1, %esi
	movl	$0, %eax
	call	fprintf
	movq	-544(%rbp), %rax
	leaq	8(%rax), %rdx
	movq	stderr(%rip), %rdi
	movl	$.LC2, %esi
	movl	$0, %eax
	call	fprintf
	movq	-544(%rbp), %rax
	leaq	16(%rax), %rdx
	movq	stderr(%rip), %rdi
	movl	$.LC3, %esi
	movl	$0, %eax
	call	fprintf
	movq	-544(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rdi
	movl	$0, %esi
	movl	$0, %eax
	call	open
	movl	%eax, -12(%rbp)
	movq	-544(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rdi
	movl	$1601, %esi
	movl	$0, %eax
	call	open
	movl	%eax, -16(%rbp)
	movq	stderr(%rip), %rdi
	leaq	-12(%rbp), %rdx
	movl	$.LC4, %esi
	movl	$0, %eax
	call	fprintf
	movq	stderr(%rip), %rdi
	leaq	-16(%rbp), %rdx
	movl	$.LC5, %esi
	movl	$0, %eax
	call	fprintf
.L2:
	movl	-12(%rbp), %edi
	leaq	-528(%rbp), %rsi
	movl	$500, %edx
	call	read
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rdx
	movl	-16(%rbp), %edi
	leaq	-528(%rbp), %rsi
	call	write
	cmpq	$0, -8(%rbp)
	jg	.L2
	movl	-12(%rbp), %edi
	call	close
	movl	-16(%rbp), %edi
	call	close
	movl	$0, %eax
	leave
	ret
.LFE2:
	.size	main, .-main
	.section	.eh_frame,"a",@progbits
.Lframe1:
	.long	.LECIE1-.LSCIE1
.LSCIE1:
	.long	0x0
	.byte	0x1
	.string	"zR"
	.uleb128 0x1
	.sleb128 -8
	.byte	0x10
	.uleb128 0x1
	.byte	0x3
	.byte	0xc
	.uleb128 0x7
	.uleb128 0x8
	.byte	0x90
	.uleb128 0x1
	.align 8
.LECIE1:
.LSFDE1:
	.long	.LEFDE1-.LASFDE1
.LASFDE1:
	.long	.LASFDE1-.Lframe1
	.long	.LFB2
	.long	.LFE2-.LFB2
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI0-.LFB2
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI1-.LCFI0
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE1:
	.ident	"GCC: (SUSE Linux) 4.3.1 20080507 (prerelease) [gcc-4_3-branch revision 135036]"
	.section	.note.GNU-stack,"",@progbits
