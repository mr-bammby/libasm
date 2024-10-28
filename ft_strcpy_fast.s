; ----------------------------------------------------------------------------------------
; Preforms functionallity of strcmp. Runs on 64-bit Linux only.
; ----------------------------------------------------------------------------------------

global    ft_strcpy


section   .text

ft_strcpy:      push rbp
                mov  rbp, rsp
                mov rax, rdi
_loop:          mov dh, byte[rsi]
                mov [rdi], dh
                cmp dh, byte 0x0
                je _end
                inc rsi
                inc rdi
                jmp _loop
_end:            mov rsp, rbp
                pop rbp
                ret
