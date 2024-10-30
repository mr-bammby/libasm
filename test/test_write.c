#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

void test_write(long (*tested_fun)(int, const void *, unsigned long), long (*reference_fun)(int, const void *, unsigned long))
{
    char sample1[] = "";
    char sample2[] = "Parampa\n";
    int errno_temp;
    int ret_ref, ret_test;
    errno = 0;

    printf("Check if both lines are same in each TEST 0 - 3. If not its FAIL\n");
    printf("Test 0 \n");
    ret_test = tested_fun(1, (void *)sample1, 0);
    errno_temp = errno;
    errno = 0;
    printf("\n");
    ret_ref = reference_fun(1, (void *)sample1, 0);
    printf("\n");
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
    ret_test = tested_fun(1, (void *)sample1, 5);
    errno_temp = errno;
    errno = 0;
    printf("\n");
    ret_ref = reference_fun(1, (void *)sample1, 5);
    printf("\n");
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
    ret_test = tested_fun(1, (void *)sample2, 3);
    errno_temp = errno;
    errno = 0;
    printf("\n");
    ret_ref = reference_fun(1, (void *)sample2, 3);
    printf("\n");
    if (errno != errno_temp)
    {
        printf("FAIL in errno \n");
    }
    errno = 0;
    if (ret_ref != ret_test)
    {
        printf("FAIL in ret value \n");

    }
    printf("Test 3 \n");
    ret_test = tested_fun(1, (void *)sample2, strlen(sample2));
    errno_temp = errno;
    errno = 0;
    printf("\n");
    ret_ref = reference_fun(1, (void *)sample2, strlen(sample2));
    printf("\n");
    if (errno != errno_temp)
    {
        printf("FAIL in errno \n");
    }
    errno = 0;
    if (ret_ref != ret_test)
    {
        printf("FAIL in ret value \n");

    }
    printf("Test 4 \n");
    ret_test = tested_fun(7, (void *)sample2, strlen(sample2));
    errno_temp = errno;
    errno = 0;
    ret_ref = reference_fun(7, (void *)sample2, strlen(sample2));
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
    int good_fd  = open("./test_file.txt", O_CREAT|O_RDWR);
    printf("In test 5 check if both lines in ./test_file.txt are equal \n");
    printf("Test 5 \n");
    ret_test = tested_fun(good_fd, (void *)sample2, strlen(sample2));
    errno_temp = errno;
    errno = 0;
    ret_ref = reference_fun(good_fd, (void *)sample2, strlen(sample2));
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
    close(good_fd);
    int bad_fd  = open("./test_file.txt", O_RDONLY);
    printf("Test 6 \n");
    ret_test = tested_fun(9, (void *)sample2, strlen(sample2));
    errno_temp = errno;
    errno = 0;
    ret_ref = reference_fun(bad_fd, (void *)sample2, strlen(sample2));
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
    close(bad_fd);
}