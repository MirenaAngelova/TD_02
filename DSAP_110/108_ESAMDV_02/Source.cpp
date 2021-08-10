// Using Hash table
// time complexity is O(n*log(k))

#include <iostream>
#include <map>

using namespace std;

void reorderArray(int A[], int N)
{
	map<int, int> elemCount;
	for (int i = 0; i < N; i++)
	{
		elemCount[A[i]]++;
	}

	int i = 0;
	for (auto it : elemCount)
	{
		while (it.second--)
		{
			A[i++] = it.first;
		}
	}
}
int main()
{
	int A[] = { 4, 2, 40, 10, 10, 1, 4, 2, 1, 10, 40 };
	int N = sizeof(A) / sizeof(A[0]);
	
	reorderArray(A, N);

	for (int i = 0; i < N; i++)
	{
		cout << A[i] << " ";
	}
}