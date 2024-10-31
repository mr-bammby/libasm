; ----------------------------------------------------------------------------------------
; Preforms functionallity of ft_list_sort. Runs on 64-bit Linux only.
;
;   Segfult if compare function pointer is not appropiate
;   Skips if begin list is NULL
;
; typedef struct s_list
; {
;   void *data;
;   struct s_list *next;
; } t_list;
;
;   void ft_list_sort(t_list **begin_list, int (*cmp)());
; ----------------------------------------------------------------------------------------

global    ft_list_sort

section   .text

ft_list_sort:   push rbp
                mov rbp, rsp
                push rbx
                push r12
                push r13
                push r14
                push r15
                push rdi; pointer to list start
                cmp rdi, 0x0
                je _end
                mov r13, qword[rdi]; pointer to current element
                mov r12, rsi
_loop:          cmp r13, 0x0
                je _end
                mov r9,  qword[rsp]
                mov r14, qword[r9] ;pointer to scanned element
                mov r15, r9 ;next of prev elelemt(at the beginig pointer to first elemet)
                mov rbx, qword[r13 + 8] ; copy next of current element, used to increase current element
                mov qword[r13 + 8], 0x0
                cmp r13, r14
                je _skip_loop   ;if scanned element is equal to current element insert isn't needed
                jmp _start_loop2
_loop2:         add r14, 8
                mov r15, r14
                mov r14, qword[r14]       
_start_loop2:   cmp r14, 0x0
                je _next_loop   ;if scanned element is equal to 0 end of the linked list
                mov rdi, [r13]
                mov rsi, [r14]
                call r12 ; call compare functiom
                cmp rax, 0x0
                jg _loop2  ; when current element is greater than scanned element go to next scanned element
_next_loop:     mov qword[r15], r13     ;insert current element
                mov qword[r13 + 8], r14
_skip_loop:     mov r13, rbx; ; increse current element
                jmp _loop
_end:           pop rdi
                pop r15
                pop r14
                pop r13
                pop r12
                pop rbx
                mov rsp, rbp
                pop rbp
                ret
