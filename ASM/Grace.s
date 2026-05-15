global main
extern dprintf
extern open
extern close
extern perror

%macro open_file 0
	xor rax, rax ; this program is a quine, it self-replicates its own source code when executed.
	lea rdi, [rel file]
	mov rsi, 577
	mov rdx, 420
	sub rsp, 8
	call open wrt ..plt
	cmp eax, 0
	jl %%print_error
	print
	ret
%%print_error:
	error
	ret
%endmacro

%macro print 0
	mov rdi, rax
	lea rsi, [rel quine]
	mov rdx, 10
	mov rcx, 9
	mov r8, 34
	lea r9, [rel quine]
	add rsp, 8
	push rax
	xor rax, rax
	call dprintf wrt ..plt
	pop rdi
	sub rsp, 8
	call close wrt ..plt
	add rsp, 8
	xor rax, rax
%endmacro

%macro error 0
	lea rdi, [rel error_msg]
	call perror wrt ..plt
	add rsp, 8
	mov rax, 1
%endmacro

section .data
	file db "Grace_kid.s", 0
	quine db "global main%1$cextern dprintf%1$cextern open%1$cextern close%1$cextern perror%1$c%1$c%%macro open_file 0%1$c%2$cxor rax, rax ; this program is a quine, it self-replicates its own source code when executed.%1$c%2$clea rdi, [rel file]%1$c%2$cmov rsi, 577%1$c%2$cmov rdx, 420%1$c%2$csub rsp, 8%1$c%2$ccall open wrt ..plt%1$c%2$ccmp eax, 0%1$c%2$cjl %%%%print_error%1$c%2$cprint%1$c%2$cret%1$c%%%%print_error:%1$c%2$cerror%1$c%2$cret%1$c%%endmacro%1$c%1$c%%macro print 0%1$c%2$cmov rdi, rax%1$c%2$clea rsi, [rel quine]%1$c%2$cmov rdx, 10%1$c%2$cmov rcx, 9%1$c%2$cmov r8, 34%1$c%2$clea r9, [rel quine]%1$c%2$cadd rsp, 8%1$c%2$cpush rax%1$c%2$cxor rax, rax%1$c%2$ccall dprintf wrt ..plt%1$c%2$cpop rdi%1$c%2$csub rsp, 8%1$c%2$ccall close wrt ..plt%1$c%2$cadd rsp, 8%1$c%2$cxor rax, rax%1$c%%endmacro%1$c%1$c%%macro error 0%1$c%2$clea rdi, [rel error_msg]%1$c%2$ccall perror wrt ..plt%1$c%2$cadd rsp, 8%1$c%2$cmov rax, 1%1$c%%endmacro%1$c%1$csection .data%1$c%2$cfile db %3$cGrace_kid.s%3$c, 0%1$c%2$cquine db %3$c%4$s%3$c, 0%1$c%2$cerror_msg db %3$cError opening file%3$c, 0%1$c%1$csection .text%1$cmain:%1$c%2$copen_file", 0
	error_msg db "Error opening file", 0

section .text
main:
	open_file