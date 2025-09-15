#include <stdio.h>
#include <monetary.h>
#include <locale.h>


int main(void)
{
	char str[32];
	setlocale(LC_ALL, "en_US.UTF-8");
	strfmon(str, sizeof(str), "%!.0n", 1234567.89);  // ! to hide '$', .0 to show only the integer part
	puts(str);
	return 0;
}

