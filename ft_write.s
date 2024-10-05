; ----------------------------------------------------------------------------------------
; Preforms functionallity of write. Runs on 64-bit Linux only.
; ----------------------------------------------------------------------------------------
global    ft_write

section   .text

ft_write:       push rbp
                mov  rbp, rsp
                mov rax, $1
                syscall
end:            mov rsp, rbp
                pop rbp
                ret
