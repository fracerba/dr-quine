global main
extern dprintf
extern snprintf
extern open
extern close
extern perror
extern access
extern system

%macro sprintf 4
	xor rax, rax
	lea rdi, [rel %1]
	mov rsi, %2
	lea rdx, [rel %3]
	mov rcx, %4
	call snprintf wrt ..plt
%endmacro

%macro execute 1
	xor rax, rax
	sprintf command, 65, %1, rbx
	lea rdi, [rel command]
	call system wrt ..plt
%endmacro

%macro print_error 1
	lea rdi, [rel %1]
	call perror wrt ..plt
	mov rax, 1
%endmacro

section .data
	N equ 5
	file_check db "Sully_5.s", 0
	file_str db "Sully_%d.s", 0
	quine db "global main%1$cextern dprintf%1$cextern snprintf%1$cextern open%1$cextern close%1$cextern perror%1$cextern access%1$cextern system%1$c%1$c%%macro sprintf 4%1$c%2$cxor rax, rax%1$c%2$clea rdi, [rel %%1]%1$c%2$cmov rsi, %%2%1$c%2$clea rdx, [rel %%3]%1$c%2$cmov rcx, %%4%1$c%2$ccall snprintf wrt ..plt%1$c%%endmacro%1$c%1$c%%macro execute 1%1$c%2$cxor rax, rax%1$c%2$csprintf command, 65, %%1, rbx%1$c%2$clea rdi, [rel command]%1$c%2$ccall system wrt ..plt%1$c%%endmacro%1$c%1$c%%macro print_error 1%1$c%2$clea rdi, [rel %%1]%1$c%2$ccall perror wrt ..plt%1$c%2$cmov rax, 1%1$c%%endmacro%1$c%1$csection .data%1$c%2$cN equ %5$d%1$c%2$cfile_check db %3$cSully_5.s%3$c, 0%1$c%2$cfile_str db %3$cSully_%%d.s%3$c, 0%1$c%2$cquine db %3$c%4$s%3$c, 0%1$c%2$ccommand_str db %3$cnasm -f elf64 -o Sully_%%1$d.o Sully_%%1$d.s && gcc Sully_%%1$d.o -o Sully_%%1$d%3$c, 0%1$c%2$ccommand_str2 db %3$c./Sully_%%d%3$c, 0%1$c%2$copen_error db %3$cError opening file%3$c, 0%1$c%2$csys_error db %3$cError compiling file%3$c, 0%1$c%2$csys_error2 db %3$cError running file%3$c, 0%1$c%2$cF_OK equ 0%1$c%1$csection .bss%1$c%2$cfile resb 10%1$c%2$ccommand resb 65%1$c%1$csection .text%1$cmain:%1$c%2$cxor rax, rax%1$c%2$cpush rbx%1$c%2$cmov rbx, N%1$c%2$ccmp rbx, 0%1$c%2$cjle return%1$c%2$clea rdi, [rel file_check]%1$c%2$cmov rsi, F_OK%1$c%2$ccall access wrt ..plt%1$c%2$ccmp eax, 0%1$c%2$cjne open_file%1$c%2$cdec rbx%1$c%1$copen_file:%1$c%2$csprintf file, 10, file_str, rbx%1$c%2$clea rdi, [rel file]%1$c%2$cmov rsi, 0o1101%1$c%2$cmov rdx, 0o644%1$c%2$ccall open wrt ..plt%1$c%2$ccmp eax, 0%1$c%2$cjl error_open%1$c%2$cmov rdi, rax%1$c%2$clea rsi, [rel quine]%1$c%2$cmov rdx, 10%1$c%2$cmov rcx, 9%1$c%2$cmov r8, 34%1$c%2$cmov r9, rsi%1$c%2$cpush rbx%1$c%2$cpush r12%1$c%2$cmov r12, rax%1$c%2$cxor rax, rax%1$c%2$ccall dprintf wrt ..plt%1$c%2$cmov rdi, r12%1$c%2$cpop r12%1$c%2$cpop rbx%1$c%2$ccall close wrt ..plt%1$c%2$cexecute command_str%1$c%2$ccmp rax, 0%1$c%2$cjl error_command%1$c%2$cexecute command_str2%1$c%2$ccmp rax, 0%1$c%2$cjl error_command2%1$c%2$cxor rax, rax%1$c%2$cjmp return%1$c%1$cerror_open:%1$c%2$cprint_error open_error%1$c%2$cjmp return%1$c%1$cerror_command:%1$c%2$cprint_error sys_error%1$c%2$cjmp return%1$c%1$cerror_command2:%1$c%2$cprint_error sys_error2%1$c%1$creturn:%1$c%2$cpop rbx%1$c%2$cret", 0
	command_str db "nasm -f elf64 -o Sully_%1$d.o Sully_%1$d.s && gcc Sully_%1$d.o -o Sully_%1$d", 0
	command_str2 db "./Sully_%d", 0
	open_error db "Error opening file", 0
	sys_error db "Error compiling file", 0
	sys_error2 db "Error running file", 0
	F_OK equ 0

section .bss
	file resb 10
	command resb 65

section .text
main:
	xor rax, rax
	push rbx
	mov rbx, N
	cmp rbx, 0
	jle return
	lea rdi, [rel file_check]
	mov rsi, F_OK
	call access wrt ..plt
	cmp eax, 0
	jne open_file
	dec rbx

open_file:
	sprintf file, 10, file_str, rbx
	lea rdi, [rel file]
	mov rsi, 0o1101
	mov rdx, 0o644
	call open wrt ..plt
	cmp eax, 0
	jl error_open
	mov rdi, rax
	lea rsi, [rel quine]
	mov rdx, 10
	mov rcx, 9
	mov r8, 34
	mov r9, rsi
	push rbx
	push r12
	mov r12, rax
	xor rax, rax
	call dprintf wrt ..plt
	mov rdi, r12
	pop r12
	pop rbx
	call close wrt ..plt
	execute command_str
	cmp rax, 0
	jl error_command
	execute command_str2
	cmp rax, 0
	jl error_command2
	xor rax, rax
	jmp return

error_open:
	print_error open_error
	jmp return

error_command:
	print_error sys_error
	jmp return

error_command2:
	print_error sys_error2

return:
	pop rbx
	ret