#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

void test_read(long (*tested_fun)(int, void *, unsigned long), long (*reference_fun)(int, void *, unsigned long))
{
    char sample1[6] = "";
    char sample1_test[6] = "";
    char sample2[100] = "";
    char sample2_test[100] = "";
    char sample3[100] = "";
    char sample3_test[100] = "";
    int errno_temp;
    int ret_ref, ret_test;
    errno = 0;

    printf("Check if both lines are same in each TEST 0 - 3. If not its FAIL\n");
    printf("Test 0 \n");
    ret_test = tested_fun(7, (void *)sample1, 0);
    errno_temp = errno;
    errno = 0;
    ret_ref = reference_fun(7, (void *)sample1, 0);
    if (errno != errno_temp)
    {
        printf("FAIL in errno \n");
    }
    errno = 0;
    if (ret_ref != ret_test)
    {
        printf("FAIL in ret value \n");
    }
    printf("Test 1 \n");
    ret_test = tested_fun(7, (void *)sample1, 5);
    errno_temp = errno;
    errno = 0;
    ret_ref = reference_fun(7, (void *)sample1, 5);
    if (errno != errno_temp)
    {
        printf("FAIL in errno \n");
    }
    errno = 0;
    if (ret_ref != ret_test)
    {
        printf("FAIL in ret value \n");
    }
    printf("Test 2 \n");
    int good_file = open("test_file.txt", O_RDONLY);
    errno = 0;
    ret_test = tested_fun(good_file, (void *)sample1, 0);
    errno_temp = errno;
    errno = 0;
    ret_ref = reference_fun(good_file, (void *)sample1_test, 0);
    printf("%s\n", sample1);
    printf("%s\n", sample1_test);
    if (errno != errno_temp)
    {
        printf("FAIL in errno \n");
    }
    errno = 0;
    if (ret_ref != ret_test)
    {
        printf("FAIL in ret value \n");
    }
    close(good_file);
    printf("Test 4 \n");
    good_file = open("test_file.txt", O_RDONLY);
    errno = 0;
    ret_test = tested_fun(good_file, (void *)sample1, 5);
    errno_temp = errno;
    close(good_file);
    good_file = open("test_file.txt", O_RDONLY);
    errno = 0;
    ret_ref = reference_fun(good_file, (void *)sample1_test, 5);
    printf("%s\n", sample1);
    printf("%s\n", sample1_test);
    if (errno != errno_temp)
    {
        printf("FAIL in errno \n");
    }
    errno = 0;
    if (ret_ref != ret_test)
    {
        printf("FAIL in ret value \n");
    }
    close(good_file);
    printf("Test 5 \n");
    good_file = open("test_file.txt", O_RDONLY);
    errno = 0;
    ret_test = tested_fun(good_file, (void *)sample2, 100);
    errno_temp = errno;
    close(good_file);
    good_file = open("test_file.txt", O_RDONLY);
    errno = 0;
    ret_ref = reference_fun(good_file, (void *)sample2_test, 100);
    printf("%s\n", sample2);
    printf("%s\n", sample2_test);
    if (errno != errno_temp)
    {
        printf("FAIL in errno \n");
    }
    errno = 0;
    if (ret_ref != ret_test)
    {
        printf("FAIL in ret value \n");
    }
    close(good_file);
    int bad_file = open("test_file.txt", O_WRONLY);
    printf("Test 6 \n");
    ret_test = tested_fun(good_file, (void *)sample3, 100);
    errno_temp = errno;
    errno = 0;
    ret_ref = reference_fun(good_file, (void *)sample3_test, 100);
    printf("%s\n", sample3);
    printf("%s\n", sample3_test);
    if (errno != errno_temp)
    {
        printf("FAIL in errno \n");
    }
    else
    {
        printf("Errno: %d\n", errno);
    }
    errno = 0;
    if (ret_ref != ret_test)
    {
        printf("FAIL in ret value \n");
    }

}
