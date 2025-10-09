#include <stdio.h>
#include <ctype.h>

#define W_MAX 100
#define W_MIN 16
#define W_DEFAULT 40

void wordwrap(FILE *file, char *text, const unsigned int width, const int option);

int main(int argc, char *argv[])
{
	/* Shakespear's 18th Sonnet */
	static char *text = "Shall I compare thee to a summer's day? \
Thou art more lovely and more temperate:\n\
Rough winds do shake the darling buds of May, \
And summer's lease hath all too short a date;\n\
Sometime too hot the eye of heaven shines, \
And often is his gold complexion dimm'd;\n\
And every fair from fair sometime declines, \
By chance or nature's changing course untrimm'd;\n\
But thy eternal summer shall not fade, \
Nor lose possession of that fair thou ow'st;\n\
Nor shall death brag thou wander'st in his shade, \
When in eternal lines to time thou grow'st:\n\
So long as men can breathe or eyes can see, \
So long lives this, and this gives life to thee.";

	// puts("Default text:");
	// puts("");
	// printf("%s\n", text);

	// char *runner = text;

	// while (*runner)
	// {
	// 	if (*runner != '\n')
	// 		putchar(*runner);
	// 	runner++;
	// }

	// runner = text;
	// while (*runner)
	// {
	// 	putchar(*runner);
	// 	runner++;
	// }

	unsigned int width = 10u; // TODO: fix BUG
	// unsigned int width = 30u;
	unsigned int opt = 0;

	wordwrap(stdout, text, width, opt);

	return (0);
}

void wordwrap(FILE *file, char *text, const unsigned int width, const int option)
{
	unsigned int line_length = 0u;
	char *line_start = text;

	do
	{
		line_length = 0u;
		/* go forward till the end of the text or up to 'width' */
		while (0 != *(line_start + line_length) && line_length < width)
		{
			line_length++;
		}

		/* go back till character is alpha or digit */
		while (line_length > 0 && isalnum(*(line_start + line_length - 1)))
		{
			line_length--;
		}
		// fprintf(stdout, "%d\n", line_length);

		/* output for -n option */
		if (1 == option)
		{
			do
			{
				if (*line_start != '\n')
					putc(*line_start, file);
				line_start++;
			} while (--line_length);
			putc('\n', file);
		}
		else /* output without -n option */
		{
			fprintf(file, "%.*s\n", line_length, line_start);
			line_start += line_length;
		}

	} while (0 != *(line_start + line_length));
}
