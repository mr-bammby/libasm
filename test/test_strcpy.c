#include <stdio.h>
#include <string.h>

void test_strcpy(char * (*tested_fun)(char *, const char *), char * (*reference_fun)(char *, const char *))
{
    char sample1_src_ref[] = "arija";
    char sample1_dest_ref[10] ;
    char sample1_src_test[] = "arija";
    char sample1_dest_test[10];

    char sample2_src_ref[] = "mumija";
    char sample2_dest_ref[20];
    char sample2_src_test[] = "mumija";
    char sample2_dest_test[20];

    char sample3_src_ref[] = "baraba";
    char sample3_dest_ref[10] = "bum\0    a";
    char sample3_src_test[] = "baraba";
    char sample3_dest_test[10] = "bum\0   a";

    char sample4_src_ref[20] = "arija";
    char *sample4_dest_ref = &sample4_src_ref[3];
    char sample4_src_test[20] = "arija";
    char *sample4_dest_test = &sample4_src_test[3];

    char sample5_dest_ref[20] = "baram";
    char *sample5_src_ref = &sample5_dest_ref[3];
    char sample5_dest_test[20] = "baram";
    char *sample5_src_test = &sample5_dest_test[3];

    char sample6_src_ref[2] = "a";
    char sample6_dest_ref[2] = "b";
    char sample6_src_test[2] = "a";
    char sample6_dest_test[2] = "b";

    char *sample_list[][4] = {{sample1_src_test, sample1_dest_test, sample1_src_ref, sample1_dest_ref},
                            {sample2_src_test, sample2_dest_test, sample2_src_ref, sample2_dest_ref},
                            {sample3_src_test, sample3_dest_test, sample3_src_ref, sample3_dest_ref},
                            {sample4_src_test, sample4_dest_test, sample4_src_ref, sample4_dest_ref}, /* Can crash Valgrind in reference strcpy */
                            {sample5_src_test, sample5_dest_test, sample5_src_ref, sample5_dest_ref},
                            {sample6_src_test, sample6_dest_test, sample6_src_ref, sample6_dest_ref}};
    int sample_list_len = 5;

    for (int i = 0; i < sample_list_len; i++)
    {
        printf("Test %d: ", i);
        if ((strcmp(tested_fun(sample_list[i][1], sample_list[i][0]), reference_fun(sample_list[i][3], sample_list[i][2])) == 0) && \
            (strcmp(sample_list[i][0], sample_list[i][2]) == 0) && (strcmp(sample_list[i][2], sample_list[i][3]) == 0))
        {
            printf("DONE\n");
        }
        else
        {
            printf("FAIL\n");
            if (strcmp(sample_list[i][0], sample_list[i][2]) != 0)
            {
                printf("Diff in source %s, %s\n", sample_list[i][0], sample_list[i][2]);
            }
            if (strcmp(sample_list[i][1], sample_list[i][3]) != 0)
            {
                printf("Diff in dest %s, %s\n", sample_list[i][1], sample_list[i][3]);
            }
        }
    }
}