/*
	Implementation of a quick sort using array
	Email: fomegnemeudje@outlook.com
	Matricule: FE20A038
*/

#include <stdio.h>
#include <malloc.h>

int *Merge(int *left, const int ll, int *right, const int lr, const int pivot) {
	// We init the merge_array
	int *merge_array = calloc(ll+lr+1, sizeof(int));

	// index in the merge_array
	int i;

	// we insert the left
	for(i=0; i<ll; i++) {
		merge_array[i] = left[i];
	}

	// we insert the pivot
	merge_array[i] = pivot;

	// we insert the right
	for(i=0; i<lr; i++) {
		merge_array[i+ll+1] = right[i];
	}

	// we return the merge list
	return merge_array;
}

int *QuickSort(int *array, const int length) {
	const int pivot = length / 2;

	int index_array;

	int *left = calloc(sizeof(int), length);

	int index_right = 0;

	int *right = calloc(sizeof(int), length);

	int index_left = 0;

	// We sort if length(array) >= 2
	if(length < 2) {
		return array;
	} else {
		for(index_array=0; index_array<length; index_array++) {
			// if ignore the pivot
			if(index_array==pivot) {
				// nothing
			}
			// we add value upper than the pivot in the right
			else if(array[index_array] > array[pivot]) {
				right[index_right++] = array[index_array];
				right = realloc(right, sizeof(int)*index_right);
			}
			// we add value less than the pivot in the left
			else {
				left[index_left++] = array[index_array];
				left = realloc(left, sizeof(int)*index_left);
			}
		}
	}

	return Merge(QuickSort(left, index_left), index_left, QuickSort(right, index_right), index_right, array[pivot]);
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
	arr = QuickSort(arr, sizeof(array)/sizeof(int));
	for(i=0; i<sizeof(array)/sizeof(int); i++) {
		printf("%i ", arr[i]);
	}
	
	return 0;
}
