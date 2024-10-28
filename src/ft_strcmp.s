; ----------------------------------------------------------------------------------------
; Preforms functionallity of strcpy. Runs on 64-bit Linux only.
; ----------------------------------------------------------------------------------------

global    ft_strcmp


section   .text

ft_strcmp:      push rbp
                mov  rbp, rsp
                xor rax, rax
                xor rdx, rdx
_loop:          mov dl, byte[rsi]
                mov al, byte[rdi]
                cmp dl, al
                jne _out
                cmp al, 0x0
                je _out
                inc rsi
                inc rdi
                jmp _loop
_out:           sub rax, rdx
                mov rsp, rbp
                pop rbp
                ret
