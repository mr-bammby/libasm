; ----------------------------------------------------------------------------------------
; Preforms functionallity of strcpy. Runs on 64-bit Linux only.
; ----------------------------------------------------------------------------------------
global    ft_strcmp


section   .text

ft_strcmp:      push rbp
                mov  rbp, rsp
                xor rax, rax
                xor rdx, rdx
loop:           mov dl, byte[rsi]
                mov al, byte[rdi]
                cmp dl, al
                jne out
                cmp al, 0x0
                je out
                inc rsi
                inc rdi
                jmp loop
out:            sub rax, rdx
                mov rsp, rbp
                pop rbp
                ret
