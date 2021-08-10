// In-place vs out-of-place algorithms

#include <iostream>

using namespace std;

void inPlaceReverse(int A[], int N)
{
	int* B = new int[N];
	copy(A, A + N, B);
	/*cout <<"\nB: ";
	for (int i = 0; i < N; i++)
	{
		cout << " " << B[i];
	}*/
	
	for (int i = 0, j = N - 1; i < j; i++, j--)
	{
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}
	cout << "\nIn-place: ";
	for (int i = 0; i < N; i++)
	{
		cout << " " << A[i];
	}
	for (int i = 0; i <= (N - 2) / 2; i++)
	{
		B[i] = B[i] ^ B[N - 1 - i];
		B[N - 1 - i] = B[i] ^ B[N - 1 - i];
		B[i] = B[i] ^ B[N - 1 - i];
	}
	cout << "\nIn-place: ";
	for (int i = 0; i < N; i++)
	{
		cout << " " << B[i];
	}
}
void reverse(int A[], int N)
{
	int* B = new int[N];
	for (int i = 0; i < N; i++)
	{
		B[N - 1 - i] = A[i];
	}

	cout << "Out-of-place: ";
	for (int i = 0; i < N; i++)
	{
		A[i] = B[i];
		cout << " " << A[i];
	}
}
int main()
{
	int A[] = { 2, 5, 6, 4, 1, 3 };
	int N = sizeof(A) / sizeof(A[0]);
	reverse(A, N);
	inPlaceReverse(A, N);
}