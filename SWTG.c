#include <math.h>
#include <stdio.h>

int main(void)
{
	///////////////
	// variables //
	///////////////

	int length = 16;
	int depth = 16;
	char arrayFormat = 'y';

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
	printf("\n*        Output is available as a list or an array of unsigned integers        *");
	printf("\n*       Please direct any questions or comments to: jamesfrize@gmail.com       *");
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

		printf("-> Array format? y/n: ");
		getchar(); // eat unwanted return char
		scanf("%c", &arrayFormat);

		printf("\n");

		////////////////////////
		// generate wavetable //
		////////////////////////

		hypotenuse = ((float)depth - 1) / 2;
		radiansPerSample = (2 * M_PI) / length;

		if(arrayFormat == 'y')
		{
			printf("{");
		}

		while(sampleIndex < length) // calculate and print each sample
		{
			radians = sampleIndex * radiansPerSample;
			amplitude = sin(radians) * hypotenuse;
			amplitude = amplitude + hypotenuse; // remove negative values
			printf("%i", (int)round(amplitude)); // round off and convert to int

			if(arrayFormat == 'y')
			{
				if(sampleIndex < length - 1)
				{
					printf(","); // separate values with a comma
				}
			}
			else printf("\n");

			sampleIndex++; // increment to the next sample
		}

		if(arrayFormat == 'y')
		{
			printf("}");
		}

		printf("\n");
		sampleIndex = 0; // reset sampleIndex
	}

  return 0;
}
