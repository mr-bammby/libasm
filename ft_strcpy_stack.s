; ----------------------------------------------------------------------------------------
; Preforms functionallity of strcpy. Runs on 64-bit Linux only.
; Saves whole string into stack. Follows behaviour of std implemntion of strcpy.
; ----------------------------------------------------------------------------------------

global    ft_strcpy

section  .note.GNU-stack

section   .text
ft_strcpy:      push rbp
                mov  rbp, rsp
                mov rax, rdi
_heap2stack:    mov dl, byte [rsi]
                push rdx
                cmp dl, 0x0
                je _stack2heap
                inc rsi
                inc rdi
                jmp _heap2stack
_stack2heap:    pop rdx
                mov byte [rdi], dl
                cmp rax, rdi
                je _end
                dec rdi
                jmp _stack2heap
_end:           mov rsp, rbp
                pop rbp
                ret