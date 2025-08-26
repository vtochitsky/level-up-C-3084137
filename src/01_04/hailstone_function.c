#include <stdio.h>
#include <stdlib.h> /* EXIT_FAILURE and EXIT_SUCCESS */

int get_hailstone(int n);

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

  do
  {
    printf("%d, ", n);
    sequence_length++;
  } while (1 != (n = get_hailstone(n)));

  /* print out the last n (1) */
  sequence_length++;
  printf("%d\n", n);

  printf("Sequence length: %zu", sequence_length);

  return EXIT_SUCCESS;
}

int get_hailstone(int n)
{
  if (0 == n % 2) /* n is even */
  {
    return n / 2;
  }
  else /* n is odd */
  {
    return n * 3 + 1;
  }

  /* it is never reached */
  return 1;
}
