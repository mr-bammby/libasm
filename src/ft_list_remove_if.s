; ----------------------------------------------------------------------------------------
; Preforms functionallity of ft_list_push_front. Runs on 64-bit Linux only.
;
; Create the function ft_list_remove_if which removes from the list, all elements
; whose data compared to data_ref using cmp, makes cmp return 0.
;
; The data from an element to be erased should be freed using free_fct
;
; segfault if any of function pointers are NULL ptr
; segfault for NULL ptr in data ref depends on cmp function
; returns with no effect if begin list is NULL
;
; typedef struct s_list
; {
;   void *data;
;   struct s_list *next;
; } t_list;
;
; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
; ----------------------------------------------------------------------------------------

global    ft_list_remove_if
extern    free

section   .text

ft_list_remove_if:  push rbp
                    mov  rbp, rsp
                    push rbx
                    push r12
                    push r13
                    push r14
                    push r15
                    cmp rdi, 0x0
                    je _end
                    mov rbx, rdi ;begining of list
                    mov r12, rsi ;data_ref
                    mov r13, rdx ;cmp_fun
                    mov r14, rcx ;data_free_fun
                    mov r15, rdi ;pointer
                    jmp _start_loop
_loop:              add rbx, 8 ;get next pointer
                    mov r15, rbx
_start_loop:        mov rdi, qword[rbx]
                    cmp rdi, 0x0
                    je _end
                    mov rbx, rdi
                    mov rdi, qword[rbx]
                    mov rsi, r12
                    call r13
                    cmp rax, 0
                    jne _loop
                    mov rdi, qword[rbx]
                    call r14
                    mov rdi, rbx
                    mov rsi, qword[rbx+8]
                    mov qword[r15], rsi 
                    mov rbx, r15
                    call free wrt ..plt
                    jmp _start_loop
_end:               pop r15
                    pop r14
                    pop r13
                    pop r12
                    pop rbx
                    mov rsp, rbp
                    pop rbp
                    ret