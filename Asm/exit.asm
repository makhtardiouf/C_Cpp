
; Simple program that exits and returns a status
; code back to the Linux Kernel
;; Using the Intel assembly syntax
	
segment .data

segment .text

	global _asm_main

_asm_main:
	enter 0, 0

	pusha
	
	mov eax, 1   ; linux kernel command number
			;(system call) for exiting a program

	mov ebx, 0   ; status number

	mov eax, 0x80	; wakes up the kernel to
			; run the exit command

	popa
