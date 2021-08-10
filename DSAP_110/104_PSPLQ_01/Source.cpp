// Solved problems on partiotioning logic of Quicksort

// Problem_01
// Sort a binary array in linear time and constant space

// Input: { 1, 0, 1, 0, 1, 0, 0, 1 }
// Output: { 0, 0, 0, 0, 1, 1, 1, 1 }

#include <iostream>
#include <algorithm>

using namespace std;

void partition(int A[], int N)
{
	int pivot = A[N - 1];
	int i = -1;
	for (int j = 0; j < N; j++)
	{
		if (A[j] < pivot)
		{
			i++;
			swap(A[i], A[j]);
		}
	}

}
int main()
{
	int A[] = { 1, 0, 0, 0, 1, 0, 1, 1 };
	int N = sizeof(A) / sizeof(A[0]);

	partition(A, N);

	for (int i = 0; i < N; i++)
	{
		cout << A[i] << " ";
	}
}