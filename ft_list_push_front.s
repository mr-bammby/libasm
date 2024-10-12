; ----------------------------------------------------------------------------------------
; Preforms functionallity of ft_list_push_front. Runs on 64-bit Linux only.
;
; typedef struct s_list
; {
;   void *data;
;   struct s_list *next;
; } t_list;
;
;   void ft_list_push_front(t_list **begin_list, void *data);
; ----------------------------------------------------------------------------------------

%macro get_data_pointer 2
    mov %1, qword[%2]
%endmacro

%macro get_data 2
    mov %1, qword[%2]
    mov %1, qword[%1]
%endmacro

%macro get_next_pointer 2
    mov %1, qword[%2 + 8]
%endmacro

%macro get_next 2
    mov %1, qword[%2 + 8]
    mov %1, qword[%1]
%endmacro

global    ft_list_push_front
extern     malloc

section   .text

ft_list_push_front: push rbp
                    mov  rbp, rsp
                    push rbx
                    push r12
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
