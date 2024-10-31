; ----------------------------------------------------------------------------------------
; Performs functionallity of ft_list_push_front. Runs on 64-bit Linux only.
;
; returns with no effect if begin list is NULL
;
; typedef struct s_list
; {
;   void *data;
;   struct s_list *next;
; } t_list;
;
;   void ft_list_push_front(t_list **begin_list, void *data);
; ----------------------------------------------------------------------------------------

global    ft_list_push_front
extern     malloc

section   .text

ft_list_push_front: push rbp
                    mov  rbp, rsp
                    push rbx
                    push r12
                    cmp rdi, 0x0
                    je _end
                    mov rbx, rdi
                    mov r12, rsi
                    mov rdi, 16 ; size of structure
                    call malloc wrt ..plt
                    cmp rax, 0
                    je _end
                    mov rsi, qword[rbx]
                    mov qword[rax], r12
                    mov qword[rax+8], rsi
                    mov qword[rbx], rax
_end:               pop r12
                    pop rbx
                    mov rsp, rbp
                    pop rbp
                    ret
