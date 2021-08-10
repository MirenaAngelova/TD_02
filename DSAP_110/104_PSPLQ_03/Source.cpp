// Problem #3
// Rearengae array alternately. Move remains
// negative or positive numbers at the end.

// Input: { 9, -3, 5, -2, -8, -6, 1, 3 }
// Output: { 5, -2, 9, -6, 1, -8, 3, -3 }

#include <iostream>
#include <algorithm>

using namespace std;

int partition(int A[], int N)
{
	int pivot = 0;
	int pivotIdx = 0;

	for (int i = 0; i < N; i++)
	{
		if (A[i] < pivot)
		{
			swap(A[i], A[pivotIdx]);
			pivotIdx++;
		}
	}

	return pivotIdx;
}
void rearrangeArray(int A[], int N)
{
	int pIdx = partition(A, N);
	for (int n = 0; pIdx < N && n < pIdx; pIdx++, n += 2)
	{
		swap(A[n], A[pIdx]);
	}
}
int main()
{
	int A[] = { 9, -3, 5, -2, -8, -6, 1, 3, -10 };
	int N = sizeof(A) / sizeof(A[0]);

	rearrangeArray(A, N);

	for (int i = 0; i < N; i++)
	{
		cout << A[i] << " ";
	}
}