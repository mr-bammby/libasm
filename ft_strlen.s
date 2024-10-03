; ----------------------------------------------------------------------------------------
; Preforms functionallity of strlen. Runs on 64-bit Linux only.
; ----------------------------------------------------------------------------------------
global    ft_strlen

section   .text

ft_strlen:      push rbp
                mov  rbp, rsp
                xor rax, rax                  
loop:           cmp byte [rdi + rax], 0x0
                je end
                inc rax
                jmp loop
end:            mov rsp, rbp
                pop rbp
                ret
