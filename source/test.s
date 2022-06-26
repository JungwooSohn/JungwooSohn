[Code]
main:
    push rbp
    mov rbp, rsp
    mov esi, 0xf
    mov rdi, 0x400500
    call 0x400497 <write_n>
    mov eax, 0x0
    pop rbp
    ret
    
write_n:
    push rbp
    mov rbp, rsp
    mov QWORD PTR [rbp-0x8],rdi
    mov DWORD PTR [rbp-0xc],esi
    xor rdx, rdx
    mov edx, DWORD PTR [rbp-0xc]
    mov rsi,QWORD PTR [rbp-0x8]
    mov rdi, 0x1
    mov rax, 0x1
    syscall
    pop rbp
    ret
    
==================================    
[Memory]
0x400500 | 0x3037207964343372
0x400508 | 0x003f367562336420