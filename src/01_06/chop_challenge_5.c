#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* implementation using standard functions from string.h */

char *left(char *s, int len)
{
	if (len > strlen(s))
	{
		// TODO: implement error handling
	}

	char *result = strdup(s); // C23
	if (NULL == result)
	{
		perror("Error in functon 'left'");
		exit(EXIT_FAILURE);
	}
	result[len] = 0; /* strndup(s, len) is better if it is implemented */

	return result;
}

char *right(char *s, int len)
{
	if (len > strlen(s))
	{
		// TODO: implement error handling
	}

	int length = strlen(s);
	char *result = strdup(s + length - len);
	if (NULL == result)
	{
		perror("Error in functon 'right'");
		exit(EXIT_FAILURE);
	}

	return result;
}

char *mid(char *s, int offset, int len)
{
	if (offset + len > strlen(s))
	{
		// TODO: implement error handling
	}

	char *result = strdup(s + offset);
	if (NULL == result)
	{
		perror("Error in functon 'mid'");
		exit(EXIT_FAILURE);
	}
	result[len] = 0; /* strndup(s, len) is better if it is implemented */

	return result;
}

int main(void)
{
	char string[] = "Once upon a time, there was a string";

	printf("Original string: %s\n", string);

	char *result = NULL;

	/* A length of original string should be checked here so that is should be >=16 and then >=18 and then >=(12+11)
	othewise it can lead to undefined behavior (possibly a segmentation fault or garbage data) */

	/* original string should be checked so that is is not a NULL like if (string == NULL) ... */

	result = left(string, 16);
	printf("Left %d characters: %s\n", 16, result);
	free(result);

	result = right(string, 18);
	printf("Right %d characters: %s\n", 18, result);
	free(result);

	result = mid(string, 12, 11); /* 12 is correct */
	printf("Middle %d characters: %s\n", 11, result);
	free(result);

	return (0);
}
