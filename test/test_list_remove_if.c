#include "../inc/libasm.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void test_list_remove_if(void)
{
    char *s1 = strdup("test.");
	char *s2 = strdup("is ");
	char *s3 = strdup("This ");

    t_list *elem1 = NULL;
	
	ft_list_push_front(&elem1, s1);
	ft_list_push_front(&elem1, s2);
	ft_list_push_front(&elem1, s3);

	ft_list_remove_if(&elem1, (void *)"MAma", strcmp, free);

    printf("Should be: 3, Actual: %d, ", ft_list_size(elem1));

	ft_list_remove_if(&elem1, (void *)"is ", strcmp, free);

    printf("Should be: 2, Actual: %d, ", ft_list_size(elem1));

	ft_list_remove_if(&elem1, (void *)"This ", strcmp, free);

    printf("Should be: 1, Actual: %d, ", ft_list_size(elem1));

	ft_list_remove_if(&elem1, (void *)"test.", strcmp, free);

    printf("Should be: 0, Actual: %d\n", ft_list_size(elem1));

	ft_list_remove_if(&elem1, (void *)"test.", strcmp, free);

	/* SEGFAULT TEST */

	ft_list_remove_if(NULL, (void *)"test.", strcmp, free);

}