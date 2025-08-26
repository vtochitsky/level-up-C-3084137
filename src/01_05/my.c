#include <stdio.h>
#include <string.h> /* for memcpy_s */

const char original_deck[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
                              'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
                              'W', 'X', 'Y', 'Z'};

#define LENGTH (sizeof(original_deck) / sizeof(original_deck[0u]))

void print_deck(const char *deck, const size_t length);
int compare_decks(const char *deck1, const char *deck2, const size_t length);
void perfect_shuffle(char *deck, const size_t length);

int main(void)
{
  char deck[LENGTH];
  size_t shuffles_counter = 0u;

  printf("Original deck: ");
  print_deck(original_deck, LENGTH);
  printf("\n");

  /* copy original deck to 'working copy' deck */
  errno_t err = memcpy_s(deck, LENGTH, original_deck, LENGTH);
  if (0 != err)
  {
    printf("memcpy_s failed with error code: %d\n", err);
  }
  else
  {
    /* nothing */
  }

  do
  {
    perfect_shuffle(deck, LENGTH);
    shuffles_counter++;
    printf("%-5d: ", shuffles_counter);
    print_deck(deck, LENGTH);
    printf("\n");
  } while (1 != compare_decks(original_deck, deck, LENGTH));

  printf("Deck restored after %d iterations", shuffles_counter);

  return 0;
}

void print_deck(const char *deck, const size_t length)
{
  size_t i;
  for (i = 0u; i < length; i++)
  {
    printf("%c", deck[i]);
  }
}

/*
The function compares two decks. If they are the same then it returns 1 oterwise 0.
*/
int compare_decks(const char *deck1, const char *deck2, const size_t length)
{
  size_t i;
  for (i = 0u; i < length; i++)
  {
    if (deck1[i] != deck2[i])
    {
      return 0;
    }
    else
    {
      /* nothing */
    }
  }

  return 1;
}

void perfect_shuffle(char *deck, const size_t length)
{
  // TODO: implement me
}
