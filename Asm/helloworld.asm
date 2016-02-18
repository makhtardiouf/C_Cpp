	;; Print "Hello, World
	segment .data
	MSG db "Hello World", 0

	segment .text
	global _start

_start:
 	push dword MSG
   	call printf
	mov eax, 1
	int 0x80
