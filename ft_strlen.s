; ----------------------------------------------------------------------------------------
; Preforms functionallity of strlen. Runs on 64-bit Linux only.
; ----------------------------------------------------------------------------------------

global    ft_strlen

section   .text

ft_strlen:      push rbp
                mov rbp, rsp
                xor rax, rax                  
_loop:          cmp byte [rdi + rax], 0x0
                je _end
                inc rax
                jmp _loop
_end:            mov rsp, rbp
                pop rbp
                ret
