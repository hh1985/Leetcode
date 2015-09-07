#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0 || citations.back() == 0) return 0;
        int i = 1, j = min(n, citations.back())+1; // The range of h: [1, n]. Exception {0, 0, 0, 1, 1}, h-index is 1.
        while (i < j) {
            int mid = i + (j - i) / 2;
            if (citations[n - mid] == mid || i == mid) return mid;
            else if (citations[n - mid] > mid) i = mid; // Increase h: h can be mid.
            else j = mid;                               // Decrease h.
        }
        return i;
    }
};

int main() {
    Solution ss;
    cout << "{0, 1, 3, 5, 6} h-index: " << ss.hIndex(vector<int>{ 0, 1, 3, 5, 6 }) << endl;
    cout << "{0, 1, 2, 5, 6} h-index: " << ss.hIndex(vector<int>{ 0, 1, 2, 5, 6 }) << endl;
    cout << "{0, 1} h-index: " << ss.hIndex(vector<int>{ 0, 1 }) << endl;
    cout << "{11, 15} h-index: " << ss.hIndex(vector<int>{ 11, 15 }) << endl;
    cout << "{1, 2} h-index: " << ss.hIndex(vector<int>{1, 2}) << endl;
    cout << "{1} h-index: " << ss.hIndex(vector<int>{1}) << endl;

}