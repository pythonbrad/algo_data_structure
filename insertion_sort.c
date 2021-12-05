/*
	Implementation of an insertion sort using array
	Email: fomegnemeudje@outlook.com
	Matricule: FE20A038
*/

#include <stdio.h>
#include <malloc.h>

int *InsertionSort(int *array, const int length) {
	int x;
	int y;
	int z;
	int temp;
	// We take an element and compare it to another elements
	for(x=0; x<length; x++) {
		for(y=0; y<x; y++) {
			// We verify the value at y in function of at x
			if(array[x] < array[y]) {
				temp = array[x];
				// We shift the values from y to x
				for(z=x-1; z>=y; z--) {
					array[z+1] = array[z];
				}
				// We insert the value at x at the position  y
				array[y] = temp;
			}
		}
	}
	return array;
}

int main() {
	int array[] = {17, 6, 3, 1, 9, 4, 8, 2, 5};
	int *arr = array;
	int i;
	printf("The initial array is ");
	for(i=0; i<sizeof(array)/sizeof(int); i++) {
		printf("%i ", arr[i]);
	}
	printf("\nThe sort array is ");
	arr = InsertionSort(arr, sizeof(array)/sizeof(int));
	for(i=0; i<sizeof(array)/sizeof(int); i++) {
		printf("%i ", arr[i]);
	}
	return 0;
}
