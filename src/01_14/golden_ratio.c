#define __USE_MINGW_ANSI_STDIO 1
// or build with -D__USE_MINGW_ANSI_STDIO=1
#include <stdio.h>

#include <math.h>  // for sqrtl()
#include <float.h> // for LDBL_DIG and LDBL_EPSILON

#ifdef __QUAD_MATH__
#include <quadmath.h> // for __float128 if needed only for GCC
#endif

// The golden ratio constant to high precision (but longer than needed for 'long double' precision)
// Source: https://oeis.org/A001622
#define GOLDEN_RATIO_LD (1.6180339887498948482045868343656381177L)
const long double Phi = 1.6180339887498948482045868343656381177L;

#define DEPTH 1000UL

long double calc_golden(size_t count);
long double func_phi(long double g, int precision); /* modified function from solution */
__float128 func_phi_qp(__float128 g, int precision);

int main()
{
  // The golden ratio constant
  const long double phi = GOLDEN_RATIO_LD;
  long double phi_calc = (1.0L + sqrtl(5.0L)) / 2.0L;

  printf("LDBL_DIG     = %d\n", LDBL_DIG); // number of decimal digits that are guaranteed to be preserved in 'long double' roundtrip without change due to rounding or overflow

  // Print the golden ratio
  // It looks that my libc does not support long double for printf() by default
  // that is why "#define __USE_MINGW_ANSI_STDIO 1" is used
  printf("           The golden ratio (phi) is approximately: %.*Lf\n", LDBL_DIG + 5, phi);
  printf("Calculated golden ratio by algebraic form formuala: %.*Lf\n", LDBL_DIG + 5, phi_calc);
  printf("     Calculated golden ratio by continued fraction: %.*Lf\n", LDBL_DIG + 5, calc_golden(DEPTH));
  printf("                            Function from solution: %.*Lf\n", LDBL_DIG + 5, func_phi(1.0L, 1000));

  // Compare the results
  if (fabsl(phi - phi_calc) < LDBL_EPSILON) // LDBL_EPSILON is the smallest such that 1.0 + LDBL_EPSILON != 1.0
    printf("The algebraic formula calculation is correct within LDBL_EPSILON (%Le)\n", LDBL_EPSILON);
  else
    printf("The algebraic formula calculation is NOT correct within LDBL_EPSILON (%Le)\n", LDBL_EPSILON);

  if (fabsl(phi - calc_golden(DEPTH)) < LDBL_EPSILON)
    printf("The continued fraction calculation is correct within LDBL_EPSILON (%Le)\n", LDBL_EPSILON);
  else
    printf("The continued fraction calculation is NOT correct within LDBL_EPSILON (%Le)\n", LDBL_EPSILON);

  if (fabsl(phi - func_phi(1.0L, 1000)) < LDBL_EPSILON)
    printf("The function from solution calculation is correct within LDBL_EPSILON (%Le)\n", LDBL_EPSILON);
  else
    printf("The function from solution calculation is NOT correct within LDBL_EPSILON (%Le)\n", LDBL_EPSILON);

#if __QUAD_MATH__
  // Now try to use __float128 if available (only for GCC)
  printf("\nNow try to use __float128 if available (only for GCC):\n");
  // __float128 can provide about 34 decimal digits of precision
  // __float128 q = 1.0Q / 3.0Q;
  // Convert to string and print
  char buf[128];
  quadmath_snprintf(buf, sizeof(buf), "%.35Qf", func_phi_qp(1.0Q, 1000)); // link with -lquadmath  !!!!
  printf("__float128: %s\n", buf);
#endif

  return 0;
}

long double calc_golden(size_t count)
{
  if (0 == count)
    return 0.0L;

  return 1.0L + 1.0L / calc_golden(count - 1);
}

long double func_phi(long double g, int precision)
{
  if (precision)
    return (g + 1 / func_phi(g, precision - 1));
  return (g);
}

#ifdef __QUAD_MATH__
    // only for GCC , link it with -lquadmath   !!!
    __float128 func_phi_qp(__float128 g, int precision)
{
  if (precision)
    return (g + 1 / func_phi_qp(g, precision - 1));
  return (g);
}
#endif
