#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include<math.h>


void insertionLetter(char letter[], int len);
void insertionNumber(int number[], int n);

void selectionLetter(char letter[], int len);
void selectionNumber(int number[], int lenN);

void bubbleLetter(char letter[], int len);
void bubbleNumber(int arr[], int lenN);

void mergeLetter(char arr[], int l, int m, int r);
void mergeSortLetter(char arr[], int l, int r);
void mergeNumber(int arr[], int l, int m, int r);
void mergeSortNumber(int arr[], int l, int r);

void printLetter(char let[], int len);
void printNumber(int num[], int n);

void swapLetter(char* xp, char* yp);
void swapNumber(int* xp, int* yp);

int partitionNum(int arr[], int low, int high);
void quickSortNumber(int arr[], int low, int high);
int partitionChar(char arr[], int low, int high);
void quickSortLetter(char arr[], int low, int high);

void heapifyNumber(int arr[], int n, int i);
void heapSortNumber(int arr[], int n);
void heapifyLetter(char name[], int charSize, int i);
void heapSortLetter(char name[], int charSize);


int main() {

	clock_t t;

	printf("Name:Bilge Kaan YUMAK \nId  :2017556507  \n");
	char letters[] = "bilgekaanyumak";
	int number[] = {2,0,1,7,5,5,6,5,0,7};

	int len = strlen(letters);
	int lenN = sizeof(number) / sizeof(number[0]);

	t = clock();

	printf("\nInsertion sort\n\n");//insertionSort
	
	insertionLetter(letters, len);
	t = clock() - t;
	printLetter(letters, len);
	printf("time: %.3f seconds\n", ((double)t) / CLOCKS_PER_SEC);


	insertionNumber(number, lenN);
	t = clock() - t;
	printNumber(number, lenN);
	printf("time: %.3f seconds\n", ((double)t) / CLOCKS_PER_SEC);




	printf("\nSelection sort\n\n");//selectionSort

	selectionLetter(letters, len);
	t = clock() - t;
	printLetter(letters, len);
	printf("time: %.3f seconds\n", ((double)t) / CLOCKS_PER_SEC);


	selectionNumber(number, lenN);
	t = clock() - t;
	printNumber(number, lenN);
	printf("time: %.3f seconds\n", ((double)t) / CLOCKS_PER_SEC);



	printf("\nBubble sort\n\n");//bubbleSort
	
	bubbleLetter(letters, len);
	t = clock() - t;
	printLetter(letters, len);
	printf("time: %.3f seconds\n", ((double)t) / CLOCKS_PER_SEC);

	bubbleNumber(number, lenN);
	t = clock() - t;
	printNumber(number, lenN);
	printf("time: %.3f seconds\n", ((double)t) / CLOCKS_PER_SEC);



	printf("\nMerge sort\n\n");//mergeSort

	mergeSortLetter(letters, 0, len - 1);
	t = clock() - t;
	printLetter(letters, len);
	printf("time: %.3f seconds\n", ((double)t) / CLOCKS_PER_SEC);

	mergeSortNumber(number, 0, lenN - 1);
	t = clock() - t;
	printNumber(number, lenN);
	printf("time: %.3f seconds\n", ((double)t) / CLOCKS_PER_SEC);






	printf("\nQuick sort\n\n");//quickSort

	quickSortLetter(letters, 0, len - 1);
	t = clock() - t;
	printLetter(letters, len);
	printf("time: %.3f seconds\n", ((double)t) / CLOCKS_PER_SEC);
	
	quickSortNumber(number, 0, lenN - 1);
	t = clock() - t;
	printNumber(number, lenN);
	printf("time: %.3f seconds\n", ((double)t) / CLOCKS_PER_SEC);


	printf("\nHeap sort\n\n");//heapSort
	
	heapSortLetter(letters, len);
	t = clock() - t;
	printLetter(letters, len);
	printf("time: %.3f seconds\n", ((double)t) / CLOCKS_PER_SEC);

	heapSortNumber(number, lenN);
	t = clock() - t;
	printNumber(number, lenN);
	printf("time: %.3f seconds\n", ((double)t) / CLOCKS_PER_SEC);

	return 0;
}


//SWAP FUNCTIONS
void swapNumber(int* fn, int* ln) {
	int temp = *fn;
	*fn = *ln;
	*ln = temp;
}
void swapLetter(char* fl, char* ll) {
	char temp = *fl;
	*fl = *ll;
	*ll = temp;
}


//INSERTION SORT PART	
void insertionLetter(char letter[], int len) {
	int i, key, j;
	for (i = 1; i < len; i++) {
		key = letter[i];
		j = i - 1;
		while (j >= 0 && letter[j] > key) {
			letter[j + 1] = letter[j];
			j = j - 1;
		}
		letter[j + 1] = key;
	}
}
void insertionNumber(int number[], int lenN) {
	int i, key, j;
	for (i = 1; i < lenN; i++) {
		key = number[i];
		j = i - 1;
		while (j >= 0 && number[j] > key) {
			number[j + 1] = number[j];
			j = j - 1;
		}
		number[j + 1] = key;
	}
}


//SELECTION SORT PART
void selectionLetter(char letter[], int len) {
	int i, j, minIndex;
	for (i = 0; i < len - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < len; j++) {
			if (letter[j] < letter[minIndex])
				minIndex = j;
		}
		swapLetter(&letter[minIndex], &letter[i]);
	}
}
void selectionNumber(int number[], int lenN) {
	int i, j, minIndex;
	for (i = 0; i < lenN - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < lenN; j++) {
			if (number[j] < number[minIndex])
				minIndex = j;
		}
		swapNumber(&number[minIndex], &number[i]);
	}
}


//BUBBLE SORT PART
void bubbleNumber(int arr[], int lenN) {
	int i, j;
	for (i = 0; i < lenN - 1; i++) {
		for (j = 0; j < lenN - i - 1; j++) {
			if (arr[j] > arr[j + 1])
				swapNumber(&arr[j], &arr[j + 1]);
		}
	}
}
void bubbleLetter(char letter[], int len) {
	int i, j;
	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - i - 1; j++) {
			if (letter[j] > letter[j + 1])
				swapLetter(&letter[j], &letter[j + 1]);
		}
	}
}


//MERGE SORT PART  

void mergeNumber(int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int*L = (int *)malloc(n1 * sizeof(int));
	int*R = (int *)malloc(n2 * sizeof(int));

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}


	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSortNumber(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSortNumber(arr, l, m);
		mergeSortNumber(arr, m + 1, r);

		mergeNumber(arr, l, m, r);
	}
}
void mergeLetter(char arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int*L = (int *)malloc(n1 * sizeof(int));
	int*R = (int *)malloc(n2 * sizeof(int));

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSortLetter(char arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSortLetter(arr, l, m);
		mergeSortLetter(arr, m + 1, r);

		mergeLetter(arr, l, m, r);
	}
}



//PRINT FUNCTIONS
void printLetter(char let[], int len) {
	int i;
	printf("sorted letters: ");
	for (i = 0; i < len; i++)
		printf("%c ", let[i]);
	printf("\n");
}
void printNumber(int num[], int lenN) {
	int i;
	printf("sorted numbers: ");
	for (i = 0; i < lenN; i++)
		printf("%d ", num[i]);
	printf("\n");
}


// Quick Sort
int partitionNum(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);
	int j;

	for (j = low; j <= high - 1; j++)
	{

		if (arr[j] < pivot)
		{
			i++;
			swapNumber(&arr[i], &arr[j]);
		}
	}
	swapNumber(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quickSortNumber(int arr[], int low, int high) {
	if (low < high)
	{
		int pi = partitionNum(arr, low, high);

		quickSortNumber(arr, low, pi - 1);
		quickSortNumber(arr, pi + 1, high);
	}
}
int partitionChar(char arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);
	int j;

	for (j = low; j <= high - 1; j++)
	{

		if (arr[j] < pivot)
		{
			i++;
			swapLetter(&arr[i], &arr[j]);
		}
	}
	swapLetter(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quickSortLetter(char arr[], int low, int high)
{
	if (low < high)
	{

		int pi = partitionChar(arr, low, high);


		quickSortLetter(arr, low, pi - 1);
		quickSortLetter(arr, pi + 1, high);
	}
}

// Heap Sort
void heapifyNumber(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;


	if (l < n && arr[l] > arr[largest])
		largest = l;


	if (r < n && arr[r] > arr[largest])
		largest = r;


	if (largest != i)
	{
		swapNumber(&arr[i], &arr[largest]);


		heapifyNumber(arr, n, largest);
	}
}
void heapSortNumber(int arr[], int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
		heapifyNumber(arr, n, i);


	for (i = n - 1; i > 0; i--)
	{

		swapNumber(&arr[0], &arr[i]);


		heapifyNumber(arr, i, 0);
	}
}
void heapifyLetter(char name[], int charSize, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < charSize && name[l] > name[largest])
		largest = l;

	if (r < charSize && name[r] > name[largest])
		largest = r;

	if (largest != i)
	{
		swapLetter(&name[i], &name[largest]);


		heapifyLetter(name, charSize, largest);
	}
}
void heapSortLetter(char name[], int charSize) {
	int i;
	for (i = charSize / 2 - 1; i >= 0; i--)
		heapifyLetter(name, charSize, i);
	for (i = charSize - 1; i > 0; i--) {

		swapLetter(&name[0], &name[i]);

		heapifyLetter(name, i, 0);
	}
}
