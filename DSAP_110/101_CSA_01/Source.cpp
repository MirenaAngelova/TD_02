// Counting Sort algorithm

#include <stdio.h>
#include <string.h>

using namespace std;
void countingSort(int A[], int N, int k)
{
	int* B = new int[N];
	int* C = new int[k];
	for (int i = 0; i <= k; i++)
	{
		C[i] = 0;
	}
	
	for (int i = 0; i < N; i++)
	{
		C[A[i]]++;
	}

	

	for (int i = 1; i <= k; i++)
	{
		C[i] += C[i - 1];
	}
	
	for (int i = 0; i < N; i++)
	{
		B[C[A[i]] - 1] = A[i];
		C[A[i]]--;
	}

	for (int i = 0; i < k + 1; i++)
	{
		printf("C[i] is %d\n", C[i]);
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d ", B[i]);
	}
}

int main()
{
	// int A[] = { 4, 2, 10, 10, 1, 4, 2, 1, 10 };
	int A[] = { 2, 5, 3, 0, 2, 3, 0, 3 };

	int N = sizeof(A) / sizeof(A[0]);

	// int k = 11;
	int k = 5;

	countingSort(A, N, k);
}