// Sort elements by their frequency and index

// Input: [3, 3, 1, 1, 1, 8, 3, 6, 8, 7, 8]
// 
// Output : [3, 3, 3, 1, 1, 1, 8, 8, 8, 6, 7]

#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <algorithm>

using namespace std;
bool value_comparer(tuple<int, int, int> const& T1,
	tuple<int, int, int> const& T2)
{
	if (get<1>(T1) != get<1>(T2))
	{
		return get<1>(T1) > get<1>(T2);
	}
	else
	{
		return get<2>(T1) < get<2>(T2);
	}
}
void sortByFreqIdx(int A[], int N)
{
	if (N < 2)
	{
		return;
	}

	unordered_map<int, pair<int, int>> elemCountIdx;
	for (int i = 0; i < N; i++)
	{
		if (elemCountIdx.find(A[i]) != elemCountIdx.end())
		{
			elemCountIdx[A[i]].first++;
		}
		else
		{
			elemCountIdx[A[i]] = make_pair(1, i);
		}
	}

	vector<tuple<int, int, int>> tuples;
	for (auto it : elemCountIdx)
	{
		pair<int, int> countIdx = it.second;
		tuples.push_back(make_tuple(it.first, countIdx.first, countIdx.second));
	}
	sort(tuples.begin(), tuples.end(), value_comparer);

	int elem = 0;
	int count = 0;
	int index = 0;
	int i = 0;

	for (auto t : tuples)
	{
		tie(elem, count, index) = t;
		for (int j = 0; j < count; j++)
		{
			A[i++] = elem;
		}
	}
}
int main()
{
	int A[] = { 3, 3, 1, 1, 1, 8, 3, 6, 8, 7, 8 };
	int N = sizeof(A) / sizeof(A[0]);

	sortByFreqIdx(A, N);

	for (int i = 0; i < N; i++)

	{
		cout << A[i] << " ";
	}
}

// Time complexity is O(n + m*log(m))
// and requires O(m) extra space