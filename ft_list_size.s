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
