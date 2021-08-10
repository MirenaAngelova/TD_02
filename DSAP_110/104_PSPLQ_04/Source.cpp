// Problem #4
// Move zeros to the end of an array

// Input: { 6, 0, 8, 2, 3, 0, 4, 0, 1 }
// Output: { 6, 8, 2, 3, 4, 1, 0, 0, 0 }

#include <iostream>
#include <algorithm>

using namespace std;

void partition(int A[], int N)
{
	int pivot = 0;
	int pivotIdx = 0;
	for (int i = 0; i < N; i++)
	{
		if (A[i] != pivot)
		{
			swap(A[i], A[pivotIdx]);
			pivotIdx++;
		}
	}
}
int main()
{
	int A[] = { 6, 0, 8, 2, 3, 0, 4, 0, 1 };
	int N = sizeof(A) / sizeof(A[0]);

	partition(A, N);

	for (int i = 0; i < N; i++)
	{
		cout << A[i] << " ";
	}
}