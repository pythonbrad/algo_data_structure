#include <stdio.h>

int main() {
	// We define the subarrays
	int arrayA[] = {2, 3, 4, 3, 6, 3};
	int arrayB[] = {3, 6, 4, 5, 8, 9, 6, 7};
	int arrayC[] = {3, 2, 5, 4};
	int arrayD[] = {3, 4, 3, 6, 4, 5, 7};
	
	// We build an array of array
	int *array[] = {arrayA, arrayB, arrayC, arrayD};

	int sum = 0;

	// We get the number of subarray
	int i = sizeof(array)/sizeof(array[0]);

	// We do the sum of each 2nd element of each subarray
	while (i--) {
		sum += array[i][1];
	};

	printf("%d", sum);
	return 0;
};