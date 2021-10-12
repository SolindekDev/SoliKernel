	.file	"print.c"
	.text
	.globl	_print_char
	.def	_print_char;	.scl	2;	.type	32;	.endef
	.seh_proc	_print_char
_print_char:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, %eax
	movb	%al, 16(%rbp)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (tdm64-1) 10.3.0"
