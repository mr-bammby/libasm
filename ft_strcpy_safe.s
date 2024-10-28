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
_skip:           cmp byte[rsi + rdx], 0x0
                je _cpy
                inc rdx
                jmp _skip
_cpy:           mov ch, [rsi + rdx]
                mov byte [rdi + rdx], ch
                cmp rdx, 0
                je _end
                dec rdx
                jmp cpy
_end:           mov rsp, rbp
                pop rbp
                ret
