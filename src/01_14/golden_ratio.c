#define __USE_MINGW_ANSI_STDIO 1
// or build with -D__USE_MINGW_ANSI_STDIO=1
#include <stdio.h>

#include <math.h> // for sqrtl()

#define GOLDEN_RATIO_LD (1.61803398874989484820458683436563811772030917980576L)
const long double Phi = 1.6180339887498948482045868343656381177203091798057628621354486227052604628189024497072072041893911375L;

#define DEPTH 1000UL

long double calc_golden(void);

int main()
{
  // The golden ratio constant
  const long double phi = GOLDEN_RATIO_LD;
  long double phi_calc = (1.0L + sqrtl(5.0L)) / 2.0L;

  // Print the golden ratio
  // It looks that my libc does not support long double for printf() by default
  printf("           The golden ratio (phi) is approximately: %.36Lf\n", phi);
  printf("Calculated golden ratio by algebraic form formuala: %.36Lf\n", phi_calc);
  printf("     Calculated golden ratio by continued fraction: %.36Lf\n", calc_golden());

  // TODO: evaluate this printing properly for all platforms
  // TODO: asserts

  return 0;
}

long double calc_golden(void)
{
  static size_t count = DEPTH;
  if (0 == --count)
    return 0.0L;

  return 1.0L + 1.0L / calc_golden();
}
