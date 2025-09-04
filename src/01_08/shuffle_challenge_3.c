#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
It is implemented in a day after after quick overivew of shuffle_solution.c
I tired to use that stuff which I still remember.
*/

#define PSIZE 20
#define RSIZE 15

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
  int recent[RSIZE];
  int unique_r_is_found;

  /* initialize */
  srand((unsigned)time(NULL));
  for (x = 0; x < PSIZE; x++)
    frequency[x] = 0;
  for (x = 0; x < RSIZE; x++)
    recent[x] = -1; /* -1 is init value due to 0 is the 1st real count value*/

  /* run through the playlist randomly */
  puts("Playlist:");
  count = 0;
  while (count < 100)
  {

    unique_r_is_found = 0;
    while (0 == unique_r_is_found)
    {

      r = rand() % PSIZE; /* random value */

      /* does r appear in recent[]? */
      for (x = 0; x < RSIZE; x++)
      {
        /* it 'r' is not unique */
        if (r == recent[x])
        {
          unique_r_is_found = 0;
          /* go to generation of new 'r' */
          break;
        }
        unique_r_is_found = 1;
      }
    }

    /* fill recent[] with 'r' so that recent[] is always keeps the last RSIZE unique 'r' */
    recent[(count + 1) % RSIZE] = r;

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
