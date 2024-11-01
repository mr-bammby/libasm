#include "../inc/libasm_bonus.h"
#include <stdlib.h>
#include <stdio.h>


void test_atoi_base(void)
{
	char base_dec[] = "0123456789";
	char base_hex[] = "0123456789ABCDEF";
	char base_oct[] = "01234567";
	char base_bin[] = "01";
	char base_one[] = "0";
	char base_empty[] = "";
	char *base_null = NULL;

	char *num0 = NULL;
    char num1[] = "";
	char num2[] = "996";
	char num3[] = "-0011";
	char num4[] = " \n \t \r -8FF";

    printf("Should be: 0, Actual: %d\n", ft_atoi_base(num0, base_null));
    printf("Should be: 0, Actual: %d\n", ft_atoi_base(num0, base_dec));
    printf("Should be: 0, Actual: %d\n", ft_atoi_base(num1, base_null));
	printf("Should be: 0, Actual: %d\n", ft_atoi_base(num1, base_dec));
	printf("Should be: 0, Actual: %d\n", ft_atoi_base(num2, base_null));
	printf("Should be: 0, Actual: %d\n", ft_atoi_base(num2, base_empty));
	printf("Should be: 0, Actual: %d\n", ft_atoi_base(num2, base_one));
	printf("Should be: 0, Actual: %d\n", ft_atoi_base(num2, base_bin));
	printf("Should be: 0, Actual: %d\n", ft_atoi_base(num2, base_oct));
	printf("Should be: 2454, Actual: %d\n", ft_atoi_base(num2, base_hex));
	printf("Should be: 996, Actual: %d\n", ft_atoi_base(num2, base_dec));
	printf("Should be: 0, Actual: %d\n", ft_atoi_base(num3, base_empty));
	printf("Should be: 0, Actual: %d\n", ft_atoi_base(num3, base_one));
	printf("Should be: -3, Actual: %d\n", ft_atoi_base(num3, base_bin));
	printf("Should be: -9, Actual: %d\n", ft_atoi_base(num3, base_oct));
	printf("Should be: -17, Actual: %d\n", ft_atoi_base(num3, base_hex));
	printf("Should be: -11, Actual: %d\n", ft_atoi_base(num3, base_dec));
	printf("Should be: 0, Actual: %d\n", ft_atoi_base(num4, base_empty));
	printf("Should be: 0, Actual: %d\n", ft_atoi_base(num4, base_one));
	printf("Should be: 0, Actual: %d\n", ft_atoi_base(num4, base_bin));
	printf("Should be: 0, Actual: %d\n", ft_atoi_base(num4, base_oct));
	printf("Should be: -2303, Actual: %d\n", ft_atoi_base(num4, base_hex));
	printf("Should be: -8, Actual: %d\n", ft_atoi_base(num4, base_dec));





}