// Find surpasser count for each array element
// 
// Find the count of elements greater
// than current aray element to its right

// Input: { 4, 6, 3, 9, 7, 10 }
// Output: { 4, 3, 3, 1, 1, 0 }

// Time complexity is O(n*log(n))

// Using Merge sort algorithm

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void merge(int B[], int aux[], int p, int q, int r, unordered_map<int, int> &elemCount)
{
	int i = p;
	int j = q + 1;
	int k = 0;
	int count = 0;
	while (i <= q && j <= r)
	{
		if (B[i] < B[j])
		{
			count++;
			aux[k++] = B[j++];
		}
		else
		{
			elemCount[B[i]] += count;
			aux[k++] = B[i++];
		}
	}

	while (i <= q)
	{
		elemCount[B[i]] += count;
		aux[k++] = B[i++];
	}

	for (int i = p; i <= r; i++)
	{
		B[i] = aux[i];
	}
}

void mergeSort(int B[], int aux[], int p, int r, unordered_map<int, int> &elemCount)
{
	if (p >= r)
	{
		return;
	}

	int q = (p + r) / 2;
	mergeSort(B, aux, p, q, elemCount);
	mergeSort(B, aux, q + 1, r, elemCount);
	merge(B, aux, p, q, r, elemCount);
}
auto surpasserCount(int A[], int N)
{
	unordered_map<int, int> elemCount;

	int* B = new int[N];
	int* aux = new int[N];


	memcpy(B, A, N * sizeof(A[0]));
	memcpy(aux, A, N * sizeof(A[0]));

	mergeSort(B, aux, 0, N - 1, elemCount);

	return elemCount;
}
int main()
{
	int A[] = { 4, 6, 3, 9, 7, 10 };
	int N = sizeof(A) / sizeof(A[0]);
	
	unordered_map<int, int> elemSurpasserCount = surpasserCount(A, N);

	for (int i = 0; i < N; i++)
	{
		cout << elemSurpasserCount[A[i]] << " ";
	}
}

// Time comlexity is O(n*log(n))


