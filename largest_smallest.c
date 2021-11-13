#include <stdio.h>

void largest_smallest(int *array, int index, int largest, int smallest) {
	if(index == sizeof(array)) {
		printf("Largest:%i\nSmallest:%i", largest, smallest);
		return;
	} else {
		if(array[index] < smallest) {
			smallest = array[index];
		} else if (array[index] > largest) {
			largest = array[index];
		} else {};
		return largest_smallest(array, index+1, largest, smallest);
	}
}

int main() {
	int array[] = {1, 3, 2, 5, 6, 4, 9, 7, 8, 0};
	largest_smallest(array, 0, 0, 0);
	return 0;
}