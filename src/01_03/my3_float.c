#include <stdio.h>
#include <math.h>	 /* fabsf() */
#include <float.h> /* FLT_EPSILON */

void making_change(float amount, int *quarters, int *dimes, int *nickels, int *pennies);

int main(void)
{
	const float amount[] = {0.49f, 1.27f, 0.75f, 1.31f, 0.83f};

	size_t i;

	for (i = 0u; i < sizeof(amount) / sizeof(amount[0]); i++)
	{
		int quarters = 0, dimes = 0, nickels = 0, pennies = 0;

		printf("Making change for: $%.2f\n", amount[i]);

		making_change(amount[i], &quarters, &dimes, &nickels, &pennies);

		printf("\t%d quarters, %d dimes, %d nickels, %d pennies\n",
					 quarters,
					 dimes,
					 nickels,
					 pennies);
	}

	return 0;
}

#define EPSILON FLT_EPSILON

void making_change(float amount, int *quarters, int *dimes, int *nickels, int *pennies)
{
	const float quarter = 0.25f;
	const float dime = 0.10f;
	const float nickel = 0.05f;
	const float penny = 0.01f;

	/* Treat 'amount' as greater than or approximately equal to 'quarter' */
	while (amount > quarter || fabsf(amount - quarter) < EPSILON)
	{
		amount -= quarter;
		(*quarters)++;
	}
	
	/* Treat 'amount' as greater than or approximately equal to 'quarter' */
	while (amount > dime || fabsf(amount - dime) < EPSILON)
	{
		amount -= dime;
		(*dimes)++;
	}

	/* Treat 'amount' as greater than or approximately equal to 'quarter' */
	while (amount > nickel || fabsf(amount - nickel) < EPSILON)
	{
		amount -= nickel;
		(*nickels)++;
	}

	/* Treat 'amount' as greater than or approximately equal to 'quarter' */
	while (amount > penny || fabsf(amount - penny) < EPSILON)
	{
		amount -= penny;
		(*pennies)++;
	}
}
