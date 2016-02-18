	;; $Id: template.asm 10 2007-12-06 13:45:15Z Makhtar $
	;; Welcome to the world of assembly programming

	;; Initialized data
	segment .data

	;; Uninitialized data
	segment .bss

	;; Code
	segment .text
	global _asm_main
_asm_main:
	enter 0, 0		; setup routine
	pusha

	;; Your main code

	popa
	leave
	mov eax, 0		; return back to C
	ret
