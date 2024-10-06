; ----------------------------------------------------------------------------------------
; Preforms functionallity of write. Runs on 64-bit Linux only.
; ----------------------------------------------------------------------------------------
            global  ft_write
            extern  __errno_location

            section .text

ft_write:   push    rbp
            mov     rbp, rsp
            mov     rax, $1
            syscall
            cmp     rax, -1
            jg      end
            neg     rax
            mov     rdi, rax
            call    __errno_location  wrt ..plt
            mov     [rax], rdi
end:        mov     rsp, rbp
            pop     rbp
            ret
