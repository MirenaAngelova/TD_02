// Count the number of inversions

// Brute-force approach
// Time complexity is O(n**2)

#include <stdio.h>

int countInversions(int A[], int N)
{
	int count = 0;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (A[i] > A[j])
			{
				count++;
			}
		}
	}
	return count;
}
int main()
{
	int A[] = { 2, 3, 8, 6, 1 };
	int N = sizeof(A) / sizeof(A[0]);

	printf("The number of inversions is %d\n", countInversions(A, N));
}