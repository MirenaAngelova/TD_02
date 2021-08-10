// Efficiently sort an array with many duplicated values

// Input: { 4, 2, 40, 10, 10, 1, 4, 2, 1, 10, 40 }
// 
// Output: { 1, 1, 2, 2, 4, 4, 10, 10, 10, 40, 40 }

// Using Counting sort

#include <stdio.h>
#include <string.h>

void printArray(int A[], int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("%d ", A[i]);
	}
}

void sortArray(int A[], int N)
{
	// int C[41];
	int C[41];
	memset(C, 0, sizeof(C));

	for (int i = 0; i < N; i++)
	{
		C[A[i]]++;
	}

	int j = 0;
	for (int i = 0; i < 41; i++)
	{
		while (C[i]--)
		{
			A[j++] = i;
		}
	}
}

int main()
{
	int A[] = { 4, 2, 40, 10, 10, 1, 4, 2, 1, 10, 40 };
	int N = sizeof(A) / sizeof(A[0]);

	sortArray(A, N);
	printArray(A, N);
}

// The counting sort algorithm takes high space complexity O(k),
// where k >> n