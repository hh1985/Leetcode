#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Top-down approach.
    int numSquares(int n) {
        vector<int> track(n, INT_MAX);
        backtrack(track, n);
        return track[n - 1];
    }

    void backtrack(vector<int>& track, int cur) {
        if (track[cur - 1] != -1) return; // Updated.
        int base = (int)sqrt(cur);
        if (base * base == cur) track[cur - 1] = 1;
        else {
            for (int i = 1; i <= base; ++i) {
                backtrack(track, cur - i * i);
                track[cur - 1] = min(track[cur - 1], track[cur - i * i - 1] + 1);
            }
        }
    }
};

int main() {
    Solution ss;
    cout << "Perfect Squares:" << endl;
    cout << "Input: 12 -> " << ss.numSquares(12) << endl;
    cout << "Input: 13 -> " << ss.numSquares(13) << endl;
}