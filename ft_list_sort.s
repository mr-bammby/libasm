; ----------------------------------------------------------------------------------------
; Preforms functionallity of ft_list_sort. Runs on 64-bit Linux only.
;
; typedef struct s_list
; {
;   void *data;
;   struct s_list *next;
; } t_list;
;
;   void ft_list_sort(t_list **begin_list, int (*cmp)());
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

global    ft_list_sort

section   .text

ft_list_sort:   push rbp
                mov rbp, rsp
                push rbx
                push r12
                push r13
                push r14
                push r15
                mov rbx, rdi; pointer to list start
                mov r13, rdi; pointer to current element
                mov r12, qword[rsi]
_loop:          cmp r13, 0x0
                je _end
                mov r14, rbx ;pointer to scanned element
                mov r15, rbx ;next of prev elelemt(at the beginig pointer to first elemet)
                jmp _start_loop2
_loop2:         add r14, 8
                mov r15, r14
                mov r14, qword[r14]       
_start_loop2:   mov rcx, qword[r13 + 8] ; copy next of current element, used to increase current element 
                cmp r13, r14
                je _next_loop   ;if scanned element is equal to current element insert isn't needed
                mov rdi, [r13]
                mov rsi, [r14]
                call r12 ; call compare functiom
                cmp rax, 0x0
                jg _loop2  ; when current element is greater than scanned element go to next scanned element
                mov qword[r15], r13     ;insert current element
                mov rdx, qword[r14 + 8] 
                mov qword[r13 + 8], rdx
_next_loop:     mov r13, rcx; ; increse current element
                jmp _loop
_end:           pop r15
                pop r14
                pop r13
                pop r12
                pop rbx
                mov rsp, rbp
                pop rbp
                ret
