; ----------------------------------------------------------------------------------------
; Preforms functionallity of strcmp. Runs on 64-bit Linux only.
; ----------------------------------------------------------------------------------------
global    ft_strcpy



section   .text

ft_strcpy:      push rbp
                mov  rbp, rsp
                mov rax, rdi
loop:           mov dh, byte[rsi]
                mov [rdi], dh
                cmp dh, byte 0x0
                je end
                inc rsi
                inc rdi
                jmp loop
end:            mov rsp, rbp
                pop rbp
                ret
