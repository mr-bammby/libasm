#include "../inc/libasm_bonus.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void test_list_sort(void)
{
    char s1[] = "QQ ";
	char s2[] = "42 ";
	char s3[] = "11 ";
	char s4[] = "Aka ";

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

	printf("elem1: %p\nelem2: %p\nelme3: %p\nelem4: %p\n", &elem1, &elem2, &elem3, &elem4);

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