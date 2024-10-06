; ----------------------------------------------------------------------------------------
; Preforms functionallity of strdup. Runs on 64-bit Linux only.
; ----------------------------------------------------------------------------------------
global    ft_strdup
extern     malloc

section   .text

ft_strdup:      push rbp
                mov  rbp, rsp
                xor rax, rax                  
str_len:        cmp byte [rdi + rax], 0x0
                je allocate
                inc rax
                jmp str_len
allocate:       push r12
                mov r12, rdi
                mov rdi, rax
                push rbx
                mov rbx, rax
                call malloc wrt ..plt
                cmp rax, 0
                je end
                xor rsi, rsi
str_cpy:        cmp rsi, rbx
                je end
                mov dl, byte[r12 + rsi]
                mov byte [rax + rsi], dl
                inc rsi
                jmp str_cpy  
end:            pop rbx
                pop r12
                mov rsp, rbp
                pop rbp
                ret
