#include <stdio.h>
#include <string.h>

void countingSort(int A[], int N, int k)
{
	int C[11];
	memset(C, 0, sizeof(C));
	for (int i = 0; i < N; i++)
	{
		C[A[i]]++;
	}

	int j = 0;
	for (int i = 0; i < k; i++)
	{
		while (C[i]--)
		{
			A[j++] = i;
		}
	}
}
int main()
{
	int A[] = { 4, 2, 10, 10, 1, 4, 2, 1, 10 };
	int N = sizeof(A) / sizeof(A[0]);

	int k = 11;
	countingSort(A, N, k);
	for (int i = 0; i < N; i++)
	{
		printf("%d ", A[i]);
	}
}