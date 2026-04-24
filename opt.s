	.file	"temp.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "Enter n: \0"
LC1:
	.ascii "%d\0"
LC2:
	.ascii "Sum = %d\12\0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB12:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$LC0, (%esp)
	call	_printf
	leal	28(%esp), %eax
	movl	$LC1, (%esp)
	movl	%eax, 4(%esp)
	call	_scanf
	movl	28(%esp), %ecx
	testl	%ecx, %ecx
	jle	L4
	addl	$1, %ecx
	xorl	%edx, %edx
	movl	$1, %eax
	.p2align 4,,10
L3:
	addl	%eax, %edx
	addl	$1, %eax
	cmpl	%ecx, %eax
	jne	L3
L2:
	movl	%edx, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	xorl	%eax, %eax
	leave
	.cfi_remember_state
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
L4:
	.cfi_restore_state
	xorl	%edx, %edx
	jmp	L2
	.cfi_endproc
LFE12:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
