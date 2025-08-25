#include <stdio.h>
#include <stdlib.h> /* EXIT_FAILURE and EXIT_SUCCESS */

int main(void)
{
  int n = 0;
  size_t sequence_length = 0u;

  printf("Enter the starting value: ");

  if (1 != scanf("%d", &n))
  {
    printf("Invalid input. Please enter an integer.\n");
    return EXIT_FAILURE;
  }

  if (n <= 0)
  {
    printf("That's not a positive integer.\n");
    return EXIT_FAILURE;
  }

  /* Input value is a positive integer (besides 123abf 3.14 and so on) */

  printf("Hailstone sequence: ");

  while (n > 0)
  {
    sequence_length++;
    printf("%d", n);
    if (1 == n) /* n is 1 */
    {
      break; /* sequence is over */
    }
    else if (0 == n % 2) /* n is even */
    {
      n = n / 2;
    }
    else /* n is odd */
    {
      n = n * 3 + 1;
    }
    printf(", ");
  }
  printf("\n");

  printf("Sequence length: %zu", sequence_length);

  return EXIT_SUCCESS;
}
