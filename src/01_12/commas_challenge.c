#include <stdio.h>

int number_us_format(char *buf, size_t buf_len, int number);

int main(void)
{
	int values[10] = {
		123, 1899, 48266, 123456, 9876543,
		10100100, 5, 500000, 99000111, 83
	};

	char strnum[64] = {0,};
	int result = 0;

	for (size_t i=0u; i<sizeof(values)/sizeof(values[0]); i++)
	{
		result = number_us_format(strnum, sizeof(strnum), values[i]);
		if ( -1 == result )
		{
			printf("String buffer is too small to format %d\n", values[i]);
			continue;
		};
		printf("%20d: %30s\n", values[i], strnum);
	}

	return(0);
}

int number_us_format(char *buf, size_t buf_len, int number)
{
	int result = 0;
	// TODO: implement me
	return result;
}
