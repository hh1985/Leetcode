#include <iostream>
#include <string>
#include <unordered_map>
#include <numeric>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num < 0) return string();
        unordered_map<int, string> unit_map{
            { 0, "Zero" },{ 1, "One" },{ 2, "Two" },{ 3, "Three" },{ 4, "Four" },{ 5, "Five" },
            { 6, "Six" },{ 7, "Seven" },{ 8, "Eight" },{ 9, "Nine" },{ 10, "Ten" },
            { 11, "Eleven" },{ 12, "Twelve" },{ 13, "Thirteen" },{ 14, "Fourteen" },{ 15, "Fifteen" },
            { 16, "Sixteen" },{ 17, "Seventeen" },{ 18, "Eighteen" },{ 19, "Nineteen" },{ 20, "Twenty" },
            { 30, "Thirty" },{ 40, "Forty" },{ 50, "Fifty" },{ 60, "Sixty" },{ 70, "Seventy" },
            { 80, "Eighty" },{ 90, "Ninety" },{ 100, "Hundred" },{ 1000, "Thousand" },{ 1000000, "Million" },
            { 1000000000, "Billion" }
        };

        if (unit_map.find(num) != unit_map.end() && num < 100) return unit_map[num];
        vector<string> res;
        int unit = 1;
        while (num > 0) {
            int tmp = num % 1000;
            // Note that the order is reversed, so the unit needs to go first.
            if (unit != 1 && tmp != 0) res.push_back(unit_map[unit]);

            // If the digit is 1x, map the word directly.
            if (tmp / 10 % 10 > 1) {
                if (tmp % 10 != 0) res.push_back(unit_map[tmp % 10]);
                res.push_back(unit_map[tmp / 10 % 10 * 10]);
            }
            else if (tmp / 10 % 10 == 1) {
                res.push_back(unit_map[tmp % 100]);
            }
            else {
                if (tmp % 10 != 0) res.push_back(unit_map[tmp % 10]);
            }

            if (tmp / 100 != 0) {
                res.push_back(unit_map[100]);
                res.push_back(unit_map[tmp / 100]);
            }

            // Convert tmp to english words.
            num /= 1000;
            unit *= 1000;
        }

        string str;
        for_each(res.rbegin(), res.rend(), [&](const string& s) { str += s; str += " "; });
        return str.substr(0, str.length() - 1);
    }

};

int main() {
    Solution ss;
    cout << "Test 1: " << ss.numberToWords(1234567) << endl;
    cout << "Test 2: " << ss.numberToWords(0) << endl;
    cout << "Test 3: " << ss.numberToWords(123) << endl;
    cout << "Test 4: " << ss.numberToWords(12345) << endl;
    cout << "Test 5: " << ss.numberToWords(110) << endl;
}