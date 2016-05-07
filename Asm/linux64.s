	# System Call Numbers on Linux
	# 64bit 
	.equ SYS_EXIT, 60
	.equ SYS_READ, 0
	.equ SYS_WRITE, 1
	.equ SYS_OPEN, 2
	.equ SYS_CLOSE, 3
	.equ SYS_BRK, 12

	# Standard File Descriptors
	.equ STDIN, 0
	.equ STDOUT, 1
	.equ STDERR, 2

	# Common Status Codes
	.equ EOF, 0

	# options for open
	.equ READ_OPTS, 0
	.equ WRITE_OPTS, 03101

	# System Call Interrupt Number
    # on 64bit use "syscall" instead