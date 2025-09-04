#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PSIZE 20
#define REPEAT 15

int main()
{
	char *playlist[PSIZE] = {
			"Like a Rolling Stone", "Satisfaction", "Imagine",
			"What's Going On", "Respect", "Good Vibrations",
			"Johnny B. Goode", "Hey Jude", "What'd I Say",
			"Smells Like Teen Spirit", "My Generation",
			"Yesterday", "Blowin' in the Wind", "Purple Haze",
			"London Calling", "I Want to Hold Your Hand",
			"Maybellene", "Hound Dog", "Let It Be",
			"A Change Is Gonna Come"};
	int frequency[PSIZE];
	int x, r, count;

	int recent[REPEAT];
	int tail;
	int r_ok;

	/* initialize */
	srand((unsigned)time(NULL));
	for (x = 0; x < PSIZE; x++)
		frequency[x] = 0;

	tail = 0;
	for (x = 0; x < REPEAT; x++)
		recent[x] = 0;

	/* run through the playlist randomly */
	puts("Playlist:");
	count = 0;
	while (count < 100)
	{

		/* generate random value which appears not often then REPEAT */
		r_ok = 0;
		do
		{
			r = rand() % PSIZE; /* random value */

			/* does r appear in recent[]? */
			for (int i = 0; i < REPEAT; i++)
			{
				if (r == recent[i])
				{
					/* generate next r */
					r_ok = 0;
					break;
				}
				else
				{
					/* exit */
					r_ok = 1;
				}
			}
		} while (r_ok == 0);

		/* store new 'r' to queue (first dequeue if needed then enqueue )*/

		/* dequeue */
		if (tail >= REPEAT)
		{
			/* throw out recent[0] and shift every item to the left */
			for (int i = 0; i < (REPEAT - 1); i++)
			{
				recent[i] = recent[i + 1];
			}
			tail = REPEAT - 1;
		}

		/* enqueue */
		recent[tail] = r;
		tail++;

		printf("%3d: Now Playing '%s'\n",
					 count + 1,
					 playlist[r]);
		frequency[r]++;
		count++;
	}

	puts("Song frequency:");
	for (x = 0; x < PSIZE; x++)
		printf("%s: %d\n", playlist[x], frequency[x]);

	return (0);
}
