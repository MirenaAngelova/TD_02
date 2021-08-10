// Problem #2
// Segregate an array of negative and positive 
// integers in lilear time and constant space.
// Negative numbers should be folowed by positive ones

// Input: { 9, -3, 5, -2, -8, -6, 1, 3 }
// Output: { -3, -2, -8, -6, 5, 9, 1, 3 }

#include <iostream>
#include <algorithm>

using namespace std;

void partition(int A[], int p, int r)
{
	int pivot = 0;
	int pivotIdx = p;
	for (int i = p; i <= r; i++)
	{
		if (A[i] < pivot)
		{
			swap(A[i], A[pivotIdx]);
			pivotIdx++;
		}
	}
}
int main() {
	int A[] = { 9, -3, 5, -2, -8, -6, 1, 3 };
	int N = sizeof(A) / sizeof(A[0]);

	partition(A, 0, N - 1);

	for (int i = 0; i < N; i++)
	{
		cout << A[i] << " ";
	}
}