#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define LENGTH 256u
static char buf[LENGTH];

char *left(char *s, int len)
{
	assert(len<LENGTH);
	int i;
	for (i=0; i<len; i++)
	{
		buf[i] = s[i];
	}
	buf[i] = 0;
	return buf;
}

char *right(char *s,int len)
{
	/* evaluate 's' length */
	int length = 0;
	char *tmp = s;
	while(*tmp++)
	{
		length++;
	}

	/* result */
	return s + length - len;
}

char *mid(char *s,int offset, int len)
{
	assert(len<LENGTH);
	int i;
	for(i=0; i < len; i++)
	{
		buf[i] = s[offset+i];
	}
	buf[i] = 0;
	return buf;
}

int main()
{
	char string[] = "Once upon a time, there was a string";

	printf("Original string: %s\n",string);
	printf("Left %d characters: %s\n",16,left(string,16));
	printf("Right %d characters: %s\n",18,right(string,18));
	printf("Middle %d characters: %s\n",11,mid(string,12,11)); /* 12 is correct */

	return(0);
}
