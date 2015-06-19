#include <math.h>
#include <stdio.h>

int main(void)
{
	///////////////
	// variables //
	///////////////

	int length = 16;
	int depth = 16;

	char isSigned = 'y';
	char isFloat = 'y';
	char isArray = 'n';

	double sampleIndex = 0;
	double amplitude = 0;

	double hypotenuse = 8;
	double radians = 0;
	double radiansPerSample = 0;

	/////////////////
	// description //
	/////////////////

	printf("\n********************************************************************************");
	printf("\n*                        -=SINE WAVE TABLE GENERATOR=-                         *");
	printf("\n********************************************************************************");
	printf("\n*  This program generates sinusoidal wavetables of varying lengths and depths  *");
	printf("\n*  Output is available in signed, unsigned, floating point and integer values  *");
	printf("\n*  The array format is useful for copying and pasting the wavetable into code  *");
	printf("\n*        Please direct any questions or comments to jamesfrize@gmail.com       *");
	printf("\n********************************************************************************");
	printf("\n");

	while(1) // loop Forever
	{
		////////////////////
		// Text interface //
		////////////////////

		printf("\n");

		printf("-> Wavetable length: ");
		scanf("%i", &length);

		printf("-> Wavetable depth: ");
		scanf("%i", &depth);

		printf("-> Signed values? y/n: ");
		getchar(); // eat unwanted return char
		scanf("%c", &isSigned);

		printf("-> Floating point values? y/n: ");
		getchar(); // eat unwanted return char
		scanf("%c", &isFloat);

		printf("-> Array format? y/n: ");
		getchar(); // eat unwanted return char
		scanf("%c", &isArray);

		printf("\n");

		////////////////////////
		// generate wavetable //
		////////////////////////

		hypotenuse = (float)depth / 2;
		radiansPerSample = (2 * M_PI) / length;

		if(isArray == 'y')
		{
			printf("{");
		}

		while(sampleIndex < length) // calculate and print each sample
		{
			radians = sampleIndex * radiansPerSample;
			amplitude = sin(radians) * hypotenuse;

			if(isSigned == 'n')
			{
				amplitude = amplitude + hypotenuse; // remove negative values
			}

			if(isFloat == 'n')
			{
				printf("%i", (int)round(amplitude)); // round off and convert to int
			}
			else printf("%f", amplitude);

			if(isArray == 'y')
			{
				if(sampleIndex < length - 1)
				{
					printf(","); // separate with a comma, unless it's the final value
				}
			}
			else printf("\n");

			sampleIndex++; // increment to the next sample
		}

		if(isArray == 'y')
		{
			printf("}");
		}

		printf("\n");

		sampleIndex = 0; // reset sampleIndex
	}

  return 0;
}
