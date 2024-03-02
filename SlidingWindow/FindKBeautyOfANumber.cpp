#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
    int stringToInt(string str) {
        return stoi(str);
    }

  public:
    int divisorSubstrings(int num, int k) {
        string s = "";
        int z = num;
        while (z) {
            s.push_back('0' + z % 10);
            z = z / 10;
        }
        int n = s.size();
        reverse(s.begin(), s.end());
        int left = 0;
        int cnt = 0;
        for (int right = 0; right < n; right++) {
            while (right - left + 1 == k) {
                int i = stringToInt(s.substr(left, right - left + 1));
                if (i != 0 && num % i == 0)
                    cnt++;
                left++;
            }
        }

        return cnt;
    }
};

int main() {
    Solution solution;
    int num = 120;
    int k = 2;
    int result = solution.divisorSubstrings(num, k);
    cout << "The number of k-digit substrings of num that are divisible by num is: " << result << endl;
    return 0;
}