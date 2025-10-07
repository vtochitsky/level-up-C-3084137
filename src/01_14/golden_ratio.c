#include <stdio.h>
#include <math.h> // for sqrtl()

#define GOLDEN_RATIO_LD (1.61803398874989484820458683436563811772030917980576L)
const long double Phi = 1.61803398874989484820458683436563811772030917980576L;

long double calc_golden(void);

int main()
{
  // The golden ratio constant
  const long double phi = GOLDEN_RATIO_LD;
  long double phi_calc = (1 + sqrtl(5.0L)) / 2;

  // Print the golden ratio
  // TODO: evaluate this printing properly for all platforms
  // printf("The golden ratio (phi) is approximately: %.36Lf\n", phi);
  // It looks that my libc does not support long double for printf()
  printf("           The golden ratio (phi) is approximately: %.17f\n", (double)phi);
  printf("Calculated golden ratio by algebraic form formuala: %.17f\n", (double)phi_calc);
  printf("     Calculated golden ratio by continued fraction: %.17f\n", (double)calc_golden());

  // TODO: asserts

  return 0;
}

long double calc_golden(void)
{
  long double golden = 0.0L;
  return golden;
}
