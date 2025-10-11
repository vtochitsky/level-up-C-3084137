#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>
#include <assert.h>

#define W_MAX 100
#define W_MIN 16
#define W_DEFAULT 40

void word_wrap(char *input, char *output, const unsigned int width, const int option);
void calc_stat(char *text, size_t *arr);

int main(int argc, char *argv[])
{
	/* Shakespear's 18th Sonnet */
	static char *in_text = "Shall I compare thee to a summer's day? \
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

	int width = W_DEFAULT;
	int opt = 0;
	char *fn = NULL;
	int out_buf_size = 0;
	int res = 0;

	while (-1 != (res = getopt(argc, argv, "hw:nf:")))
	{
		switch (res)
		{
		case 'h':
			printf("Possible options: -h -n -w[number] -f[file_name]\n"
						 "\t -h is this help\n"
						 "\t -w is output text width\n"
						 "\t -n to ommit newline characters from input text\n"
						 "\t -f is input file name to process\n");
			exit(EXIT_SUCCESS);
			break;
		case 'w':
			width = atoi(optarg);
			// /* saturate */
			// if (width < W_MIN)
			// {
			// 	width = W_MIN;
			// }
			// else if (width > W_MAX)
			// {
			// 	width = W_MAX;
			// }
			// else
			// {
			// 	/* nothing */
			// }
			break;
		case 'n':
			opt = 1;
			break;
		case 'f':
			fn = optarg;
			break;
		case '?':
			printf("Wrong options. Run program with option -h.");
			exit(EXIT_FAILURE);
			break;
		default:
			break;
		}
	}

	char *file_buf = NULL;
	/* if file name is provided, read text from file */
	if (NULL != fn)
	{
		FILE *infile = fopen(fn, "r");

		if (NULL == infile)
		{
			perror("Error opening file");
			return 1;
		}

		fseek(infile, 0, SEEK_END);
		long fsize = ftell(infile);
		rewind(infile);

		file_buf = (char *)malloc(fsize + 1);
		if (file_buf == NULL)
		{
			perror("Memory allocation failed");
			fclose(infile);
			exit(EXIT_FAILURE);
		}

		size_t read_size = fread(file_buf, 1, fsize, infile);
		file_buf[read_size] = '\0';

		in_text = file_buf;

		fclose(infile);
	}

	printf("%s\n\n", in_text);

	out_buf_size = strlen(in_text);
	out_buf_size += out_buf_size / width + 1; /* */

	char *out_text = (char *)calloc(out_buf_size, sizeof(char));
	if (NULL == out_text)
	{
		perror("Memory for output text was not allocated");
		exit(EXIT_FAILURE);
	}

	word_wrap(in_text, out_text, width, opt);

	printf("%s\n\n", out_text);

	/* TEST PART */
	size_t ar_input[256] = {
			0,
	};

	calc_stat(in_text, ar_input);

	size_t ar_output[256] = {
			0,
	};

	calc_stat(out_text, ar_output);

	puts("Assert that input content equals to output one (ignoring '\\n' character).");
	for (size_t i = 0; i < 10; i++)
	{
		// printf("%3zu %7zu %7zu %s\n", i, ar_input[i], ar_output[i], ar_input[i] != ar_output[i] ? "<---!!!" : "");
		assert(ar_input[i] == ar_output[i]);
	}
	/* ignore \n here */
	for (size_t i = 11; i < 256; i++)
	{
		// printf("%3zu %7zu %7zu %s\n", i, ar_input[i], ar_output[i], ar_input[i] != ar_output[i] ? "<---!!!" : "");
		assert(ar_input[i] == ar_output[i]);
	}

	free(out_text);

	if (NULL != file_buf)
		free(file_buf);

	return (0);
}

void word_wrap(char *input, char *output, const unsigned int width, const int option)
{
	unsigned int line_length = 0u;
	char *line_start = input;

	do
	{
		line_length = 0u;
		/* go forward till the end of the text or up to 'width' */
		while (0 != *(line_start + line_length) && line_length < width)
		{
			line_length++;
		}

		/* go back till character is alpha or digit */
		unsigned int len = line_length;
		while (line_length > 0 && isalnum(*(line_start + line_length - 1)))
		{
			line_length--;
		}
		if (0u == line_length)
		{
			line_length = len;
		}

		do
		{
			if (1 == option && *line_start == '\n')
			{
				line_start++;
				continue;
			}
			*(output++) = *(line_start++);
		} while (--line_length);
		*(output++) = '\n';

	} while (0 != *(line_start + line_length));

	*output = 0;
}

void calc_stat(char *text, size_t *arr)
{
	while (*text)
	{
		arr[(unsigned char)(*text)]++;
		text++;
	}
}
