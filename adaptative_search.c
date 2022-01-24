/*
	Implementation of an sequential search using array
	Email: fomegnemeudje@outlook.com
	Matricule: FE20A038
*/

#include <stdio.h>

// This function permit to search an element in an array
// put the search item in the top of the list
int search1(int *array, int element, int length) {
	int i;
	int temp;

	// We verify if the element is present in the array 
	for(i=0; i<length; i++) {
		if(array[i] == element) {
			// We put the search item in the top
			temp = array[i];
			array[i] = array[0];
			array[0] = temp;
			return i;
		}
	}

	// In this point, the element is not found
	return -1;
}

// This function permit to search an element in an array
// advance the search item one step toward the top of the list
int search2(int *array, int element, int length) {
	int i;
	int temp;

	// We verify if the element is present in the array 
	for(i=0; i<length; i++) {
		if(array[i] == element) {
			// if the element is located at the index 0, no need to advance
			if(i==0) {
				return 0;
			} else {
				// We advance the search item
				temp = array[i];
				array[i] = array[i-1];
				array[i-1] = temp;
				return i;
			}
		}
	}

	// In this point, the element is not found
	return -1;
}

int main() {
	int array[100] = {89, 4, 91, 11, 59, 65, 63, 14, 88, 44, 3, 95, 55, 85, 60, 18, 28, 83, 2, 9, 36, 49, 57, 86, 74, 27, 56, 58, 69, 34, 73, 87, 6, 99, 93, 66, 32, 47, 79, 92, 75, 22, 35, 48, 70, 40, 33, 80, 10, 50, 7, 51, 37, 64, 98, 19, 12, 39, 62, 46, 17, 1, 29, 15, 78, 24, 13, 71, 96, 45, 20, 82, 77, 54, 68, 97, 90, 81, 42, 8, 67, 72, 76, 16, 53, 30, 84, 38, 5, 25, 26, 21, 43, 23, 94, 41, 0, 31, 61, 52};
	
	printf("31 found at the index %i\n", search1(array, 31, 100));
	printf("31 found at the index %i\n", search1(array, 31, 100));
	printf("41 found at the index %i\n", search2(array, 41, 100));
	printf("41 found at the index %i\n", search2(array, 41, 100));
	printf("41 found at the index %i\n", search2(array, 41, 100));
	printf("41 found at the index %i\n", search2(array, 41, 100));
	printf("41 found at the index %i\n", search2(array, 41, 100));
	printf("41 found at the index %i\n", search2(array, 41, 100));

	return 0;
}