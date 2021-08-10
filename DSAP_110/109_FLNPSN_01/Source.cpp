// Find the largest possible number
// formed by the set numbers

// Input: { 10, 68, 75, 7, 21, 12 }
// Output: 77568211210

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct {
    bool operator()(string a, string b) const
    {
        string A = a + b;
        string B = b + a;

        return A > B;
    }
} customCompare;

int main()
{
    vector<string> V = { "10", "68", "97", "9", "21", "12" };

    sort(begin(V), end(V), customCompare);

    for (const auto& elem : V) {
        cout << elem;
    }

    return 0;
}

// Time complexity is O(n*log(n))