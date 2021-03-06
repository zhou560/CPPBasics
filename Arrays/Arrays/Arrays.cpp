/*Array manipulations.*/

#include "stdafx.h"
#include <stdlib.h>

//Use a constant to fix the size of the array, as well as all operations on it.
#define SIZE 10

//Print out the contents of array, along with an optional name
void printArray(int* a, const char* name = "\0") {
	printf("%s\n", name);
	for (int i = 0; i < SIZE; i++) {
		printf("%d, ", a[i]);
	}
	printf("\n");
}

//Produce a copy of the array and its elements. The destination must be allocated beforehand.
int* copyArray(int* dest, int* a) {
	//memcpy returns a void *; convert it into an int * to return
	return (int*)memcpy(dest, a, SIZE * sizeof(int));
}

//Sort the array using insertion sort.
void insertionSort(int* a) {
	//Iterate through all elements
	for (int i = 1; i < SIZE; i++) {
		//For each element, swap it with previous element if it is less than it
		for (int j = i; a[j] < a[j - 1] && j >= 0; j--) {
			int temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
		}
	}
}

//Partition the array around a pivot
int qpartition(int* a, int l, int r) {
	//The pivot is naively chosen to be the rightmost element.
	int p = a[r];
	int i = l - 1;
	int temp;
	for (int j = l; j < r; j++) {
		if (a[j] < p) {
			i++;
			//swap a[i] and a[j]
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[i + 1];
	a[i + 1] = a[r];
	a[r] = temp;
	return i + 1;
}

//Sort the array using quicksort
void quickSort(int* a, int l, int r) {
	if (l < r) {
		int p = qpartition(a, l, r);
		quickSort(a, l, p - 1);
		quickSort(a, p + 1, r);
	}
}

int main(){
	//Create an array of ints
	int source[SIZE];
	//Set each element to a random int between 0 and 100
	for (int i = 0; i < SIZE; i++) {
		source[i] = rand() % 100;
	}
	printArray(source, "source");
	
	//A copy of source. Operations will be performed on this sample.
	int sample[SIZE];
	copyArray(sample, source);
	insertionSort(sample);

	printArray(sample, "insertion sort");

	copyArray(sample, source);
	quickSort(sample, 0, SIZE - 1);
	printArray(sample, "quick sort");

    return 0;
}

