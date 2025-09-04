#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PSIZE 20
#define RSIZE 15
#define COUNT 100

int main(void)
{
	char *playlist[PSIZE] = {
			"Like a Rolling Stone",
			"Satisfaction",
			"Imagine",
			"What's Going On",
			"Respect",
			"Good Vibrations",
			"Johnny B. Goode",
			"Hey Jude",
			"What'd I Say",
			"Smells Like Teen Spirit",
			"My Generation",
			"Yesterday",
			"Blowin' in the Wind",
			"Purple Haze",
			"London Calling",
			"I Want to Hold Your Hand",
			"Maybellene",
			"Hound Dog",
			"Let It Be",
			"A Change Is Gonna Come",
	};

	int frequency[PSIZE];
	int recent[RSIZE]; /* holds recently-played songs */
	int x, r, count, found;
	int full_list[COUNT];

	/* initialize */
	srand((unsigned)time(NULL));

	for (x = 0; x < PSIZE; x++)
		frequency[x] = 0;

	for (x = 0; x < RSIZE; x++)
		recent[x] = -1; /* -1 because no element is -1 */

	for (x = 0; x < COUNT; x++)
		full_list[x] = -1; /* -1 because no element is -1 */

	/* run through the playlist randomly */
	puts("Playlist:");
	count = 0;
	while (count < COUNT)
	{
		/* does r appear in the recent[] list? */
		found = 1; /* assume it does */
		while (found)
		{
			r = rand() % PSIZE; /* random song from the list */
			found = 0;					/* not found yet */
			/* see if the song was recently-played */
			for (x = 0; x < RSIZE; x++)
			{
				if (r == recent[x])
					found = 1; /* found! */
			}
			/* found==0 here if the song isn't in the
				 recently-played list */
		}

		/* add the song to the recently-played list */
		recent[count % RSIZE] = r;

		/* play the song */
		printf("%3d: Now Playing '%s'\n",
					 count + 1,
					 playlist[r]);
		frequency[r]++;
		full_list[count] = r;
		count++;
	}

	puts("Song frequency:");
	for (x = 0; x < PSIZE; x++)
		printf("%s: %d\n", playlist[x], frequency[x]);

	puts("");
	/* Check RSIZE distance in full_list[] */
	printf("Check %d 'distance' in full_list[%d]...\n", RSIZE, COUNT);
	int exit_nexted_loops = 0;
	for (x = 0; (x < COUNT - RSIZE) && (0 != exit_nexted_loops); x++)
	{
		for (int y = x + 1; y <= x + RSIZE; y++)
		{
			if (full_list[x] == full_list[y])
			{
				// printf("ALGORITHM FAILED: %d 'distance' is not statisfied\n", RSIZE);
				exit_nexted_loops = 1;
				break;
			}
		}
	}

	if (1 == exit_nexted_loops)
	{
		printf("ALGORITHM FAILED: 'distance' is NOT statisfied\n");
	}
	else
	{
		printf("ALGORITHM PASSED: 'distance' is statisfied\n");
	}

	return (0);
}
