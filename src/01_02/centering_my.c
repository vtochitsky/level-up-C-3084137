#include <stdio.h>
#include <string.h>

void center_text(int width, char *text)
{
	int offset = (width + strlen(text)) / 2;

	if (offset < 0)
	{
		offset = 0;
	}

	printf("%*s\n", offset, text);
}

int main()
{
	/* some sample text to center */
	char *title[] = {
			"March Sales",
			"My First Project",
			"Centering output is so much fun!",
			"This title is very long, just to see whether the code can handle such a long title"};
	int x;

	/* output each of the strings, centered */
	for (x = 0; x < 4; x++)
	{
		/* assume the screen width to be 80 characters */
		center_text(80, title[x]);
	}

	return (0);
}
