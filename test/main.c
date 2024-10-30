#include "inc/libasm.h"
#include "inc/test.h"
#include <stdio.h>
#include <string.h>

void main(void)
{
    printf("<-------- STR LEN ------->\n");
    test_strlen(ft_strlen, strlen);
    printf("<-------- STR CMP ------->\n");
    test_strcmp(ft_strcmp, strcmp);
    printf("<-------- STR CPY ------->\n");
    test_strcpy(ft_strcpy, strcpy);

}
