#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PSIZE 20

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
  int recent[PSIZE];
  int x, r, count;

  /* initialize */
  srand((unsigned)time(NULL));
  for (x = 0; x < PSIZE; x++)
    recent[x] = frequency[x] = 0;

  /* run through the playlist randomly */
  puts("Playlist:");
  count = 0;
  while (count < 100)
  {

    do
    {
      r = rand() % PSIZE; /* random value */

      if ((0 == recent[r]) || (count - recent[r]) > 15)
      {
        recent[r] = count + 1;
        break;
      }

    } while (1); /* Not reliable code !!! INIFINIT LOOP IS POSSIBLE !!! NOT TESTED WELL. Any code change can cause it. */

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
