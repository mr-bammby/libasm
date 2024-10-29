; ----------------------------------------------------------------------------------------
; Preforms functionallity of atoi_base. Runs on 64-bit Linux only.
; input:
; pointer to input string
; pointer to string of base 
;
; program flow:
;   setup:
;       1. skip space chars space(0x20), \t(0x09), \n(0x0a), \v(0x0b), \f(0x0c), \r(0x0d)
;       2. sign detection (optional)
;       3. save address of first number char (depending on base) (jumnp to isnumcahr)
;       4. iterate over num sting
;       5. find last number char (jumnp to isnumcahr)
;       6. assign base len to factor
;       7. assign base 0 to accumulator
;       8. assign last number char to current char
;   loop:
;       1. transform value of current char into a number (jump to char2num)
;       2. multiply transformed number with factor
;       3. add result to accumulator
;       4. if current char is first char jump to end
;       5. decrement current char
;       6. multiply factor with base
;   end:
;       1. if sign is negative multipy accumulator with -1
;       2. return accumulator
;
;   isnumchar:
;       1. if char in a base jump setup(4)
;       2. else setup(5)
;   char2num:
;       1. Get index of char in base
;       2. retun index
;
; int ft_atoi_base(char *src, char *base)
; ----------------------------------------------------------------------------------------


;skips character adnh jumps to given label
%macro skip_char 2
    cmp byte [rdi], %1
    je %2
%endmacro

;Finds the firat case of char in base
;keep in mind uses local lables
%macro  find_in_base 1
            xor r10, r10
.base_loop: cmp byte[rsi + r10], %1
            je .base_end
            cmp byte[rsi + r10], 0x00 ;\0
            je .base_end
            inc r10
            jmp .base_loop
.base_end:  
%endmacro

global    ft_atoi_base

section   .text

ft_atoi_base:   push rbp
                mov rbp, rsp
                xor rdx, rdx ;num_itr
                xor r11, r11 ;sign
                xor r10, r10 ;base_itr
_mea_base:      cmp byte[rsi + r10], 0x00 ;\0
                je _mea_base_end
                inc r10
                jmp _mea_base
_mea_base_end:  mov r9, r10 ;base_len
                cmp r9, 2
                jl _end
                jmp _skip_sp_begin
_skip_sp_loop:  inc rdi               
_skip_sp_begin: skip_char ' ', _skip_sp_loop
                skip_char 0x09, _skip_sp_loop ;\t
                skip_char 0x0a, _skip_sp_loop ;\n
                skip_char 0x0b, _skip_sp_loop ;\v
                skip_char 0x0c, _skip_sp_loop ;\f
                skip_char 0x0d, _skip_sp_loop ;\r
_det_sign:      skip_char '+', _det_sign_end
                cmp byte [rdi], '-'
                jne _num_cnt_loop
                inc r11
_det_sign_end:  inc rdi
_num_cnt_loop:  mov cl, byte [rdi + rdx]
                cmp cl, 0x0
                je _num_cnt_end
                find_in_base cl
                cmp r10, r9
                je _num_cnt_end
                inc rdx
                jmp _num_cnt_loop
_num_cnt_end:   mov r8, 1 ; factor
                xor rax, rax ;accumulator
_add_loop:      cmp rdx, 0
                je _add_end
                dec rdx
                mov cl, byte [rdi + rdx]
                find_in_base cl
                imul r10, r8
                add rax, r10
                imul r8, r9
                jmp _add_loop
_add_end:       cmp r11, 0
                je _end
                neg rax
_end:           mov rsp, rbp
                pop rbp
                ret
