#include <stdio.h>

size_t my_str_len(char *str);
void reverse(char *str, size_t str_len);
int number_us_format(char *str, size_t str_len, int number);

int main(void)
{
	int values[10] = {
			123, 1899, 48266, 123456, 9876543,
			10100100, 5, 500000, 99000111, 83};

	char strnum[64] = {
			0,
	};
	int result = 0;

	for (size_t i = 0u; i < sizeof(values) / sizeof(values[0]); i++)
	{
		result = number_us_format(strnum, sizeof(strnum), values[i]);
		if (-1 == result)
		{
			printf("String buffer is too small to format %d\n", values[i]);
			continue;
		};
		printf("%20d: %30s\n", values[i], strnum);
	}

	return (0);
}

size_t my_str_len(char *str)
{
	size_t len = 0u;
	while (*str++)
	{
		len++;
	}
	return len;
}

void reverse(char *str, size_t str_len)
{
	char c;
	for (size_t i = 0u; i < str_len / 2; i++)
	{
		c = str[i];
		str[i] = str[str_len - 1 - i];
		str[str_len - 1 - i] = c;
	}
}

int number_us_format(char *str, size_t str_len, int number)
{
	size_t len = 0u;
	char *orig_str = str;
	int comma_cnt = 0;

	while (0 != number && len <= str_len)
	{
		if (3 == comma_cnt)
		{
			comma_cnt = 0;
			*str++ = ',';
			len++;
		};
		*str++ = number % 10 + '0';
		len++;
		comma_cnt++;
		number /= 10;
	}
	*str = 0;
	reverse(orig_str, len);

	return len < str_len ? len : -1;
}
