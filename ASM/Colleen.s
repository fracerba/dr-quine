global main
extern printf

section .data
	quine db "global main%1$cextern printf%1$c%1$csection .data%1$c%2$cquine db %3$c%4$s%3$c, 0%1$c%1$c; this comment is outside the entry point routine%1$c%1$csection .text%1$cmain:%1$c%2$cxor rax, rax ; this comment is inside the entry point routine%1$c%2$clea rdi, [rel quine]%1$c%2$cmov rsi, 10%1$c%2$cmov rdx, 9%1$c%2$cmov rcx, 34%1$c%2$cmov r8, rdi%1$c%2$cjmp return%1$c%1$creturn:%1$c%2$csub rsp, 8%1$c%2$ccall printf wrt ..plt%1$c%2$cadd rsp, 8%1$c%2$cxor rax, rax%1$c%2$cret", 0

; this comment is outside the entry point routine

section .text
main:
	xor rax, rax ; this comment is inside the entry point routine
	lea rdi, [rel quine]
	mov rsi, 10
	mov rdx, 9
	mov rcx, 34
	mov r8, rdi
	jmp return

return:
	sub rsp, 8
	call printf wrt ..plt
	add rsp, 8
	xor rax, rax
	ret