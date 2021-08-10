// Reorder elements of an array 
// based on their order in another array

// The elements in first array that does not appear in second one
// should be append to the end in sorted order.
// The second array can contain the elems does not appear in the first one.

// Input:
// first { 5, 8, 9, 3, 5, 7, 1, 3, 4, 9, 3, 5, 1, 8, 4 }
// second { 3, 5, 7, 2 }

// Output: [3, 3, 3, 5, 5, 5, 7, 1, 1, 4, 4, 8, 8, 9, 9]

// Using Hashing

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

void printArray(int first[], int F)
{
	for (int i = 0; i < F; i++)
	{
		cout << first[i] << " ";
	}
}
void reorderArray(int first[], int second[], int F, int S)
{
	unordered_map<int, int> firstElemCount;

	for (int i = 0; i < F; i++)
	{
		firstElemCount[first[i]]++;
	}

	int firstIdx = 0;
	for (int i = 0; i < S; i++)
	{
		while (firstElemCount[second[i]])
		{
			first[firstIdx++] = second[i];
			firstElemCount[second[i]]--;
		}

		firstElemCount.erase(second[i]);
	}

	int sortFirstIdx = firstIdx;
	for (auto it = firstElemCount.begin(); it != firstElemCount.end(); it++)
	{
		while (it->second--)
		{
			first[firstIdx++] = it->first;
		}
	}

	sort(first + sortFirstIdx, first + firstIdx);
}
int main()
{
	int first[] = { 5, 8, 9, 3, 5, 7, 1, 3, 4, 9, 3, 5, 1, 8, 4 };
	int second[] = { 3, 5, 7, 2 };

	int F = sizeof(first) / sizeof(first[0]);
	int S = sizeof(second) / sizeof(second[0]);

	reorderArray(first, second, F, S);
	printArray(first, F);
}

// Time complexity is O(m*log(m) + n)