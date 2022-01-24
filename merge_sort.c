/*
	Implementation of a merge sort using array
	Email: fomegnemeudje@outlook.com
	Matricule: FE20A038
*/

#include <stdio.h>
#include <malloc.h>

// This function merge and ordered
int *MergeOrdered(int *left, const int len_left, int *right, const int len_right) {
	// the id in the merge array 
	int i=0;

	// the id in the left array
	int id_left=0;

	// the if in the right array
	int id_right=0;

	// we allow memory for the merge array
	int *merge_array = calloc(sizeof(int), len_left+len_right);

	// The value that we insert is the upper between next left and next right
	while(i < (len_left + len_right)) {
		if(left[id_left] >= right[id_right] && id_left != len_left) {
			merge_array[i++] = left[id_left++];
		} else {
			if(id_right != len_right) {
				merge_array[i++] = right[id_right++];
			}
		}
	}
	// we return the merge array
	return merge_array;
}

// This function sort element in an array from index a to b
int *MergeSort(int *array, const int len) {
	// We calcul the middle
	const int m = (int) (len / 2);

	int i;

	// We declare the left array and right array
	int *left = NULL;
	int *right = NULL;

	// We return the array
	if(len == 1)
	{
		return array;
	}
	// Otherwise we split
	else
	{
		left = calloc(sizeof(int), m);
		right = calloc(sizeof(int), len-m);

		// We copy value for the left and right
		for(i=0; i<m; i++) {
			left[i] = array[i];
		}

		for(i=m; i<len; i++) {
			right[i-m] = array[i];
		}

		// We split the list in two parts
		left = MergeSort(left, m);
		right = MergeSort(right, len-m);

		// We merge sort and merge them
		return MergeOrdered(left, m, right, len-m);
	}
}

int main() {
	int x = 0;
	int array[] = {1, 9, 3, 6, 2, 7, 4, 0, 8, 5};
	int length = sizeof(array) / sizeof(int);
	int *arr = array;

	printf("The initial array is ");
	
	for(x = 0; x < length; x++)
	{
		printf("%i ", arr[x]);
	}

	arr = MergeSort(array, length);

	printf("\nThe sort array is ");

	for(x = 0; x < length; x++)
	{
		printf("%i ", arr[x]);
	}

	return 0;
}