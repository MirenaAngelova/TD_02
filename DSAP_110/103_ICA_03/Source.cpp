#include <stdio.h>

int merge(int A[], int aux[], int p, int q, int r)
{
	int k = p;
	int i = p;
	int j = q + 1;
	int inversions = 0;
	while (i <= q && j <= r)
	{
		if (A[i] <= A[j])
		{
			aux[k++] = A[i++];
		}
		else
		{
			aux[k++] = A[j++];
			inversions += q - i + 1;
		}
	}

	while (i <= q)
	{
		aux[k++] = A[i++];
	}

	for (int i = p; i <= r; i++)
	{
		A[i] = aux[i];
	}
	return inversions;
}

int mergeSort(int A[], int aux[], int p, int r)
{
	if (p == r)
	{
		return 0;
	}

	int q = p + ((r - p) >> 1);
	int inversions = 0;

	inversions += mergeSort(A, aux, p, q);
	inversions += mergeSort(A, aux, q + 1, r);
	inversions += merge(A, aux, p, q, r);

	return inversions;
}

int main()
{
	int A[] = { 1, 9, 6, 4, 5 };
	int N = sizeof(A) / sizeof(A[0]);

	int* aux = new int[N];
	for (int i = 0; i < N; i++)
	{
		aux[i] = A[i];
	}

	printf("The number of inversions is %d", mergeSort(A, aux, 0, N - 1));
}