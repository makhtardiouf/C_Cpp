	#Common Linux Definitions

	# 64bit System Call Numbers
	.equ SYS_EXIT, 60
	.equ SYS_READ, 0
	.equ SYS_WRITE, 1
	.equ SYS_OPEN, 2
	.equ SYS_CLOSE, 3
	.equ SYS_BRK, 12

	#System Call Interrupt Number
    # on 64bit use "syscall" instead
	/*.equ CALL_KERNEL, 0x80 */

	#Standard File Descriptors
	.equ STDIN, 0
	.equ STDOUT, 1
	.equ STDERR, 2

	#Common Status Codes
	.equ EOF, 0

	# options for open
	.equ READ_OPTS, 0
	.equ WRITE_OPTS, 03101
