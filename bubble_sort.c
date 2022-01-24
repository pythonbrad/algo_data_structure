/*
	Implementation of an bubble sort using array
	Email: fomegnemeudje@outlook.com
	Matricule: FE20A038
*/

#include <stdio.h>

// This function sort element in an array
void BubbleSort(int *array, const int length)
{
	int x = 0;
	int y = 0;
	int temp;

	// This first loop permit to repeat the bubble sort
	// to have a complete bubble sort
	for(x = 0; x < length; x++)
	{
		// This loop permit to swap a number if array[x] < array[x+1]
		for(y = 0; y < length-1; y++)
		{
			if(array[y] < array[y+1]) {
				temp = array[y];
				array[y] = array[y+1];
				array[y+1] = temp;
			}
		}
	}
}

int main()
{
	int x = 0;

	int array[] = {1, 5, 2, 9, 0, 2, 5, 4};

	int *arr = array;

	int length = sizeof(array)/sizeof(int);

	printf("The initial array is ");

	for(x = 0; x < length; x++)
	{
		printf("%i ", arr[x]);
	}

	BubbleSort(arr, length);

	for(x = 0; x < length; x++)
	{
		printf("%i ", arr[x]);
	}

	printf("\nThe sort array is ");

	for(x = 0; x < length; x++)
	{
		printf("%i ", arr[x]);
	}
	
	return 0;
}