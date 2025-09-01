#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char *left(char *s, int len)
{
	assert(len >= 0);
	char *result = (char *)malloc(len + 1);
	if (NULL == result)
	{
		// perror("Memory not allocated in functon 'left'"); /* requires string.h */
		fprintf(stderr, "Memory not allocated in functon 'left'");
		exit(EXIT_FAILURE);
	}
	int i;
	for (i = 0; i < len; i++) // like strncpy(result, s, len);
	{
		result[i] = s[i];
	}
	result[i] = 0;
	return result;
}

/* this function can be implemented without malloc but to be more consisten it uses malloc in the same style like others */
char *right(char *s, int len)
// {
// 	/* evaluate 's' length */
// 	int length = 0;
// 	char *tmp = s;
// 	while (*tmp++)
// 	{
// 		length++;
// 	}

// 	/* result */
// 	return s + length - len;
// }
{
	assert(len >= 0);
	char *result = (char *)malloc(len + 1);
	if (NULL == result)
	{
		// perror("Memory not allocated in functon 'right'"); /* requires string.h */
		fprintf(stderr, "Memory not allocated in functon 'right'");
		exit(EXIT_FAILURE);
	}

	/* evaluate 's' full length like strlen(s) */
	int length = 0;
	char *tmp = s;
	while (*tmp++)
	{
		length++;
	}
	int i;
	for (i = 0; i < len; i++)
	{
		result[i] = s[length - len + i];
	}
	result[i] = 0;
	/* result */
	return result;
}

char *mid(char *s, int offset, int len)
{
	assert(len >= 0);
	char *result = (char *)malloc(len + 1);
	if (NULL == result)
	{
		// perror("Memory not allocated in functon 'mid'"); /* requires string.h */
		fprintf(stderr, "Memory not allocated in functon 'mid'");
		exit(EXIT_FAILURE);
	}
	int i;
	for (i = 0; i < len; i++)
	{
		result[i] = s[offset + i];
	}
	result[i] = 0;
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

/*

// An example of more safe version of function

char *left(const char *s, int len) {
		assert(len >= 0);
		if (s == NULL) {
				fprintf(stderr, "Input string is NULL\n");
				exit(EXIT_FAILURE);
		}

		int actual_len = strlen(s);
		int copy_len = len < actual_len ? len : actual_len;

		char *result = malloc(copy_len + 1);
		if (result == NULL) {
				perror("Memory not allocated in function 'left'");
				exit(EXIT_FAILURE);
		}

		strncpy(result, s, copy_len);
		result[copy_len] = '\0';
		return result;
}

*/
