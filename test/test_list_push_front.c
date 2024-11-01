#include "../inc/libasm_bonus.h"
#include <stdlib.h>
#include <stdio.h>


void test_list_push_front(void)
{
    char s1[8] = "test.";
	char s2[4]= "is ";
	char s3[] = "This ";

    t_list *elem1 = NULL;
	

    printf("Should be: 0, Actual: %d, ", ft_list_size(elem1));

	ft_list_push_front(&elem1, s1);

    printf("Should be: 1, Actual: %d, ", ft_list_size(elem1));

	ft_list_push_front(&elem1, s2);

    printf("Should be: 2, Actual: %d, ", ft_list_size(elem1));

	ft_list_push_front(&elem1, s3);

    printf("Should be: 3, Actual: %d\n", ft_list_size(elem1));

	printf("Should be: This is test. Actual: ");

	while (elem1 != NULL)
	{
		printf("%s", (char *)elem1->data);
		t_list *temp = elem1;
		elem1 = elem1->next;
		free(temp);
	}
	
	/* SEGFAUL test*/
	ft_list_push_front(NULL, NULL);

	printf("\n");

}