; ----------------------------------------------------------------------------------------
; Preforms functionallity of strdup. Runs on 64-bit Linux only.
; ----------------------------------------------------------------------------------------
global    ft_strdup
extern     malloc

section   .text

ft_strdup:      push rbp
                mov  rbp, rsp
                xor rax, rax                  
_str_len:       cmp byte [rdi + rax], 0x0
                je _allocate
                inc rax
                jmp _str_len
_allocate:      push r12
                mov r12, rdi
                mov rdi, rax
                push rbx
                mov rbx, rax
                call malloc wrt ..plt
                cmp rax, 0
                je _end ; return if malloc failed
                xor rsi, rsi
_str_cpy:       cmp rsi, rbx
                je _end
                mov dl, byte[r12 + rsi]
                mov byte [rax + rsi], dl
                inc rsi
                jmp _str_cpy  
_end:            pop rbx
                pop r12
                mov rsp, rbp
                pop rbp
                ret
