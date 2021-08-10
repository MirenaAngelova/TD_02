// Count the number of inversions
// using merge sort in O(n*lgn) time

#include <stdio.h>
#include<limits.h>

int mergeInversions(int A[], int p, int q, int r)
{
	int N1 = q - p + 1;
	int N2 = r - q;
	int* L = new int[N1 + 1];
	int* R = new int[N2 + 1];
	
	for (int i = 0; i <= N1; i++)
	{
		L[i] = A[p + i];
	}

	for (int j = 0; j <= N2; j++)
	{
		R[j] = A[q + 1 + j];
	}
	L[N1] = INT_MAX;
	R[N2] = INT_MAX;
	int i = 0;
	int j = 0;
	int inversions = 0;
	// bool counted = false;
	for (int k = p; k <= r; k++)
	{
		/*if (!counted && L[i] > R[j])
		{
			
			inversions += N1 - i;
			counted = true;
		}

		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
			counted = false;
		}*/
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			inversions += N1 - i;
			A[k] = R[j];
			j++;
		}
	}
	return inversions;
}
int countInversions(int A[], int p, int r)
{
	int inversions = 0;
	if (p < r)
	{
		int q = (p + r - 1) / 2;
		inversions += countInversions(A, p, q);
		inversions += countInversions(A, q + 1, r);
		inversions += mergeInversions(A, p, q, r);
	}
	return inversions;
}
int main()
{
	// int A[] = { 2, 3, 8, 6, 1 };
	// int A[] = { -1, -75, 5, 4, 8, -70, 6, 3, 0 };
	// int A[] = { -1, -75, 5, 4, 8, -70, 6, 3, 0, 10 };
	// int A[] = { -1, -75, 5, 4, 8, -70, 6, 3, 0, 7 };
	// 17
	int A[] = { 1, 9, 6, 4, 5 };
	int N = sizeof(A) / sizeof(A[0]);

	printf("The number of inversions is %d", countInversions(A, 0, N - 1));
}