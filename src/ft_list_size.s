; ----------------------------------------------------------------------------------------
; Preforms functionallity of ft_list_size. Runs on 64-bit Linux only.
;
; typedef struct s_list
; {
;   void *data;
;   struct s_list *next;
; } t_list;
;
;   int ft_list_size(t_list *begin_list);
; ----------------------------------------------------------------------------------------

global    ft_list_size

section   .text

ft_list_size: push rbp
                    mov rbp, rsp
                    xor rax, rax
_loop:               cmp rdi, 0x0
                    je _end
                    inc rax
                    mov rdi, [rdi + 8]
                    jmp _loop
_end:               mov rsp, rbp
                    pop rbp
                    ret
