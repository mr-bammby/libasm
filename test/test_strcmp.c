#include <stdio.h>

void test_strcmp(int (*tested_fun)(const char *, const char *), int (*reference_fun)(const char *, const char *))
{
    char sample1_l[] = "";
    char sample1_r[] = "";
    char sample2_l[] = "ABA";
    char sample2_r[] = "";
    char sample3_l[] = "";
    char sample3_r[] = "ABA";
    char sample4_l[] = "ABA";
    char sample4_r[] = "ABA";
    char sample5_l[] = "RASvfs";
    char sample5_r[] = "RAS\0fs";
    char sample6_l[] = "ArrBA";
    char sample6_r[] = "ABA";
    char *sample7_l = 0;
    char sample7_r[] = "ABA";

    char *sample_list[][2] = {{sample1_l, sample1_r},
                            {sample2_l, sample2_r},
                            {sample3_l, sample3_r},
                            {sample4_l, sample4_r},
                            {sample5_l, sample5_r},
                            {sample6_l, sample6_r},
                            {sample7_l, sample7_r}};
    int sample_list_len = 6;

    for (int i = 0; i < sample_list_len; i++)
    {
        printf("Test %d: ", i);
        if (tested_fun(sample_list[i][0], sample_list[i][1]) == reference_fun(sample_list[i][0], sample_list[i][1]))
        {
            printf("DONE\n");
        }
        else
        {
            printf("FAIL\n");
        }
    }

}