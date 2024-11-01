#include "../inc/libasm_bonus.h"
#include <stdlib.h>
#include <stdio.h>


void test_list_size(void)
{
    char s1[8] = "Mim\0";
	char s2[4]= "hji";
	char s3[5] = "Test";

    t_list elem1;
	elem1.data = (void*)s2;
	elem1.next = NULL;
	
	t_list elem2;
	elem2.data = (void*)s3;
	elem2.next = NULL;

	t_list elem3;
	elem3.data = (void*)s1;
	elem3.next = NULL;

    elem1.next = &elem2;
    elem2.next = &elem3;

    printf("Should be: 0, Actual: %d, ", ft_list_size(NULL));
    printf("Should be: 1, Actual: %d, ", ft_list_size(&elem3));
    printf("Should be: 2, Actual: %d, ", ft_list_size(&elem2));
    printf("Should be: 3, Actual: %d\n", ft_list_size(&elem1));


}