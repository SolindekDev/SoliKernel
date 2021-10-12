	.file	"std.c"
	.text
	.globl	printf_char
	.def	printf_char;	.scl	2;	.type	32;	.endef
	.seh_proc	printf_char
printf_char:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, %eax
	movb	%al, 16(%rbp)
/APP
 # 26 "src/lib/std.c" 1
	mov  $'H' , %al
	movb $0x0e, %ah
	int  $0x10
	
 # 0 "" 2
/NO_APP
	nop
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (tdm64-1) 10.3.0"
