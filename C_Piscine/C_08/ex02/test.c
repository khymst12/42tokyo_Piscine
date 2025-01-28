#include "ft_abs.h"
#include <stdio.h>

int	main(void)
{
	printf("ABS(-42) = %d\n", ABS(-42));       // 結果: 42
	printf("ABS(42) = %d\n", ABS(42));         // 結果: 42
	printf("ABS(0) = %d\n", ABS(0));           // 結果: 0
	printf("ABS(-1234) = %d\n", ABS(-1234));   // 結果: 1234
	printf("ABS(5 - 10) = %d\n", ABS(5 - 10)); // 結果: 5
	return (0);
}
