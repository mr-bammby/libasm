; ----------------------------------------------------------------------------------------
; Preforms functionallity of strcpy. Runs on 64-bit Linux only.
; ----------------------------------------------------------------------------------------
global    ft_strcmp


section   .text

ft_strcmp:      push rbp
                mov  rbp, rsp
                mov rax, $0
loop:           mov dh, byte[rsi]
                mov ch, byte[rdi]
                cmp dh, ch
                jne out
                cmp dh, 0x0
                je end
                inc rsi
                inc rdi
                jmp loop
end:            mov rax, $1
out:            mov rsp, rbp
                pop rbp
                ret
