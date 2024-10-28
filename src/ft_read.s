; ----------------------------------------------------------------------------------------
; Preforms functionallity of read. Runs on 64-bit Linux only.
; ----------------------------------------------------------------------------------------

            global  ft_read
            extern  __errno_location

            section .text

ft_read:   push    rbp
            mov     rbp, rsp
            mov     rax, $0
            syscall
            cmp     rax, -1
            jg      _end
            neg     rax
            mov     rbx, rax
            call    __errno_location  wrt ..plt
            mov     [rax], rbx
            mov     rax, -1
_end:       mov     rsp, rbp
            pop     rbp
            ret
