#include <stdio.h>

void making_change(float am, int *qua, int *dim, int *nic, int *pen);

int main(void)
{
	float amount[] = {0.49f, 1.27f, 0.75f, 1.31f, 0.83f};

	size_t i;

	for(i=0u; i < sizeof(amount)/sizeof(amount[0]); i++)
	{
		int quarters=0, dimes=0, nickels=0, pennies=0;

		printf("Making change for: $%.2f\n",amount[i]);

		making_change(amount[i],&quarters,&dimes,&nickels,&pennies);

		printf("\t%d quarters, %d dimes, %d nickels, %d pennies\n",
			quarters,
			dimes,
			nickels,
			pennies
			);
	}

    return 0;
}

void making_change(float am, int *qua, int *dim, int *nic, int *pen)
{
	const int quarter = 25, dime = 10, nickel = 5, penny = 1;

	int int_amount = am * 100.0f; /* convert amount to coins */

	*qua = *dim = *nic= *pen = 0;

	while( int_amount >= quarter )
	{
		int_amount -= quarter;
		(*qua)++;
	}
	while( int_amount >= dime )
	{
		int_amount -= dime;
		(*dim)++;
	}
	while( int_amount >= nickel )
	{
		int_amount -= nickel;
		(*nic)++;
	}
	while( int_amount >= penny )
	{
		int_amount -= penny;
		(*pen)++;
	}
}
