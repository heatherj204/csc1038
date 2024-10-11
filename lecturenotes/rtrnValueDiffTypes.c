#include <stdio.h>
#include <stdlib.h>

void findMax(float a[], int length, float *value, int *position);

int main(int argc, char *argv[])
{
	float a[] = {1,2,3,4,5,6};
	float value = -999; /* just initialise a number outside of the range */
	int pos = -999; /* just initialise a number outside of the range */

	findMax(a, sizeof(a)/sizeof(a[0]), &value, &pos);
	printf("The max value %f can be found at %d\n", value, pos);
}

void findMax(float a[], int length, float *value, int *position)
{
	*value = a[0];
	for(int i = 1; i < length; ++i)
	{
		if (a[i] > *value)
		{
			*value = a[i];
			*position = i;
		}
	}
}