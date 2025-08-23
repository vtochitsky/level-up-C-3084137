#include <stdio.h>

int main()
{
	const float quarter = 0.25f;
	const float dime = 0.1f;
	const float nickel = 0.05f;
	const float penny = 0.01f;

	float test_amount[] = {0.49f, 1.27f, 0.75f, 1.31f, 0.83f};

	int i;
	for (i = 0; i < sizeof(test_amount) / sizeof(test_amount[0]); i++)
	{
		size_t quarters = 0u;
		size_t dimes = 0u;
		size_t nickels = 0u;
		size_t pennies = 0u;

		float test_value = test_amount[i];
		printf("Making change for: $%f\n", test_amount[i]);

		while (test_value >= quarter)
		{
			test_value -= quarter;
			// printf("q %f\n", test_value);
			quarters++;
		}

		while (test_value >= dime)
		{
			test_value -= dime;
			// printf("d %f\n", test_value);
			dimes++;
		}

		while (test_value >= nickel)
		{
			test_value -= nickel;
			// printf("n %f\n", test_value);
			nickels++;
		}

		printf("penny %.8f\n", penny);
		while (test_value >= penny)
		{
			test_value -= penny;
			printf("p %.8f\n", test_value);
			pennies++;
		}

		printf("\t%d quarters, %d dimes, %d nickels, %d pennies\n",
					 quarters,
					 dimes,
					 nickels,
					 pennies);
	}

	return (0);
}
