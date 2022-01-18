#include <stdio.h>

void smallest_largest(int* arr, int length, int* result)
{
	// We evaluate the middle
	float middle = 1.0 * length / 2.0;

	if (length == 1)
	{
		*result = (*result > *arr) ? *result : *arr;
		*(result + 1) = (*(result + 1) < *arr) ? *(result + 1) : *arr;
	}
	else
	{
		smallest_largest(arr, middle, result);
		smallest_largest(arr + (int) middle, middle + 0.5, result);
	}
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 100};

	// By default, the result is the first element of this array
	int result[2] = {arr[0], arr[0]};

	smallest_largest(arr, sizeof(arr) / sizeof(int), result);

	printf("The smallest is %d and the greatest is %d\n", result[0], result[1]);

	return 0;
};