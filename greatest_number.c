#include <stdio.h>

int largest(int* arr, int length)
{
	int a;
	int b;

	// We evaluate the middle
	float middle = 1.0 * length / 2.0;

	// We limit the divide and conquer when we have just 1 element
	if (length == 1)
	{
		return *arr;
	}
	else
	{
		a = largest(arr, middle);

		b = largest(arr + (int) middle, middle + 0.5);

		return (a > b) ? a : b;
	}
}


int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 100};

	printf("%i\n", largest(arr, sizeof(arr)/sizeof(int)));
	
	return 0;
};