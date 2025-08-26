#include <stdio.h>
#include <stdlib.h> /* EXIT_FAILURE and EXIT_SUCCESS */

int hailstone_rec(int n, size_t *length);

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

  hailstone_rec(n, &sequence_length);

  printf("Sequence length: %zu", sequence_length);

  return EXIT_SUCCESS;
}

int hailstone_rec(int n, size_t *length)
{
  (*length)++;

  if (1 == n)
  {
    /* print the last 1 */
    printf("%d\n", n);

    /* exit */
    return 1;
  }

  printf("%d, ", n);

  if (0 == n % 2) /* n is even */
  {
    return hailstone_rec(n / 2, length);
  }
  else /* n is odd */
  {
    return hailstone_rec(n * 3 + 1, length);
  }
}
