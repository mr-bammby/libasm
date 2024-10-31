#include "../inc/libasm.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void test_list_sort(void)
{
    char s1[] = "TT ";
	char s2[] = "Mia ";
	char s3[] = "WTF ";
	char s4[] = "Mio ";

	t_list *start = NULL;

    t_list elem1;
	elem1.data = (void*)s1;
	elem1.next = NULL;
	
	t_list elem2;
	elem2.data = (void*)s2;
	elem2.next = NULL;

	t_list elem3;
	elem3.data = (void*)s3;
	elem3.next = NULL;

	t_list elem4;
	elem4.data = (void*)s4;
	elem4.next = NULL;

	ft_list_sort(&start, strcmp);

	while (start != NULL)
	{
		printf("%s\n", (char *)start->data);
		t_list *temp = start;
		start = start->next;
	}
	printf("\n");

	start = &elem1;
	ft_list_sort(&start, strcmp);

	while (start != NULL)
	{
		printf("%s\n", (char *)start->data);
		t_list *temp = start;
		start = start->next;
	}
	printf("\n");

	start = &elem1;
	elem1.next = &elem2;
	ft_list_sort(&start, strcmp);

	while (start != NULL)
	{
		printf("%s\n", (char *)start->data);
		t_list *temp = start;
		start = start->next;
	}
	printf("\n");

	start = &elem1;
	elem1.next = &elem2;
	elem2.next = &elem3;
	ft_list_sort(&start, strcmp);

	while (start != NULL)
	{
		printf("%s\n", (char *)start->data);
		t_list *temp = start;
		start = start->next;
	}
	printf("\n");

	start = &elem1;
	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = &elem4;
	ft_list_sort(&start, strcmp);

	while (start != NULL)
	{
		printf("%s\n", (char *)start->data);
		t_list *temp = start;
		start = start->next;
	}
	printf("\n");
}