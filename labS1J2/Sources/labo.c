#include "labo.h"

void insertionSort(int elements[], int n) {
	int y;
	int temp;
	for (int i = 1; i < n; i++) {
		y = i;
		while (y > 0 && elements[y] < elements[y - 1]) {
			temp = elements[y];
			elements[y] = elements[y - 1];
			elements[y - 1] = temp;
			--y;
		}
	}
};

void quickSort(int* elements, int left, int right) {
	if (left >= right) { return; }
	int L = left; int R = right;
	int Pivot = elements[(left + right) / 2];
	
	while (left <= right) {
		while (elements[left] < Pivot) { left++; }
		while (elements[right] > Pivot) { right--; }
		if (left <= right) {
			int temp;
			temp = elements[left];
			elements[left] = elements[right];
			elements[right] = temp;
			left++; right--;
		}
	}

	int index = left;
	quickSort(elements, L, index - 1);
	quickSort(elements, index, R);

};