#include <stdio.h>

void test_strlen(unsigned long (*tested_fun)(const char *), unsigned long (*reference_fun)(const char *))
{
    char sample1[] = "";
    char sample2[] = "12345678 112456";
    char sample3[] = "12345678\0112456";
    char sample4[] = "\0";

    char *sample_list[] = {sample1, sample2, sample3, sample4};
    int sample_list_len = 4;

    for (int i = 0; i < sample_list_len; i++)
    {
        printf("Test %d: ", i);
        if (tested_fun(sample_list[i]) == reference_fun(sample_list[i]))
        {
            printf("DONE\n");
        }
        else
        {
            printf("FAIL\n");
        }
    }

}