#include <stdio.h>

char *ordinal(int v)
{
        char *suffix = "th";
        if (v >= 10 && v <=20)
        {
            /* nothing to do*/
        }
        else
        {
            int x = v % 10;
            if ( x == 1)
            {
                suffix = "st";
            }
            else if ( x == 2)
            {
                suffix = "nd";
            }
            else if ( x == 3)
            {
                suffix = "rd";
            }
            else
            {
                /* nothing to do */
            };
        }
    return suffix;
}

int main()
{
	int c;

	/* output a table of 100 numbers */
	for( c=1; c<=20; c++ )
	{
		printf("%3d%s\t%3d%s\t%3d%s\t%3d%s\t%3d%s\n",
				c, ordinal(c),
				c+20, ordinal(c+20),
				c+40, ordinal(c+40),
				c+60, ordinal(c+60),
				c+80, ordinal(c+80)
			  );
	}

	return(0);
}
