#include "../inc/libasm.h"
#include "../inc/libasm_bonus.h"
#include "../inc/test.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    printf("<-------- STR LEN ------->\n");
    test_strlen(ft_strlen, strlen);
    printf("<-------- STR CMP ------->\n");
    test_strcmp(ft_strcmp, strcmp);
    printf("<-------- STR CPY ------->\n");
    test_strcpy(ft_strcpy, strcpy);
    printf("<-------- WRITE --------->\n");
    test_write(ft_write, write);
    printf("<-------- READ --------->\n");
    test_read(ft_read, read);
    printf("<-------- STR DUP ------->\n");
    test_strdup(ft_strdup, strdup);
    printf("<-------- ATOI BASE ----->\n");
    test_atoi_base(); 
    printf("<-------- LIST SIZE ----->\n");
    test_list_size();
    printf("<----- LIST PUSH FRONT -->\n");
    test_list_push_front();
    printf("<----- LIST REMOVE IF -->\n");
    test_list_remove_if();
    printf("<----- LIST SORT ------->\n");
    test_list_sort();

    return(0);
}
