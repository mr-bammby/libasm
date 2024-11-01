#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_strdup(char * (*tested_fun)(const char *), char * (*reference_fun)(const char *))
{
    char sample1[] = "";
    char sample2[] = "12345678 112456";
    char sample3[] = "12345678 \0a112456";
    char *sample4 = strdup("HnjoHnjo\0");
    char *sample5 =  0; /* Seagfault in original function. */
    char *test;
    char* ref;

    char *sample_list[] = {sample1, sample2, sample3, sample4};
    int sample_list_len = 4;

    for (int i = 0; i < sample_list_len; i++)
    {
        printf("Test %d: \n", i);
        ref = reference_fun(sample_list[i]);
        test = tested_fun(sample_list[i]);
        printf("%s\n", ref);
        printf("%s\n", test);
        if (strcmp(ref, test) == 0)
        {
            printf("DONE\n");
        }
        else
        {
            printf("FAIL\n");
        }
        free(ref);
        free(test);
    }
    free(sample4);
}