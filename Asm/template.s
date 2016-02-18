/* $Id: template.s 18 2008-07-06 09:18:48Z Makhtar $
  */

.section .data

.section .text
.globl _start
_start:
/* Main code */


	movl $1, %eax
	int $0x80
