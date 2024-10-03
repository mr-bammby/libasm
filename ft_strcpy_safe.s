; ----------------------------------------------------------------------------------------
; Preforms functionallity of strcpy. Runs on 64-bit Linux only.
; ----------------------------------------------------------------------------------------
global    ft_strcpy

section  .note.GNU-stack

section   .text

ft_strcpy:      push rbp
                mov  rbp, rsp
                mov rax, rdi
                xor rdx, rdx
skip:           cmp byte[rsi + rdx], 0x0
                je cpy
                inc rdx
                jmp skip
cpy:            mov ch, [rsi + rdx]
                mov byte [rdi + rdx], ch
                cmp rdx, 0
                je end
                dec rdx
                jmp cpy
end:            mov rsp, rbp
                pop rbp
                ret
