#include <stdio.h>
#include <string.h> /* for memcpy_s */
#include <assert.h> /* for assert */

const char original_deck[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
                              'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
                              'W', 'X', 'Y', 'Z',};
//			      '0', '1', '2', '3', '4', '5','6', '7','8','9'};

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
  memcpy(deck, original_deck, LENGTH);

  do
  {
    perfect_shuffle(deck, LENGTH);
    shuffles_counter++;
    printf("%-5zu: ", shuffles_counter);
    print_deck(deck, LENGTH);
    printf("\n");
  } while (1 != compare_decks(original_deck, deck, LENGTH));

  printf("Deck restored after %zu iterations\n", shuffles_counter);

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
  assert(length > 0);

  const size_t half = length / 2;
  char buffer[length]; // VLA

  size_t j = 0u;
  size_t i;
  for (i = 0u; i < length - 1u; i += 2u)
  {
    buffer[i] = deck[j];
    j++;
  }

  for (i = 1u; i < length; i += 2u)
  {
    buffer[i] = deck[j];
    j++;
  }

  memcpy(deck, buffer, length);
}
