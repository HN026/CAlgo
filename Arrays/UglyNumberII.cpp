#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0; // Invalid input
        if (n == 1) return 1; // The first ugly number is 1

        vector<int> ugly(n);
        ugly[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        int next_multiple_of_2 = 2;
        int next_multiple_of_3 = 3;
        int next_multiple_of_5 = 5;

        for (int i = 1; i < n; i++) {
            int next_ugly = min({next_multiple_of_2, next_multiple_of_3, next_multiple_of_5});
            ugly[i] = next_ugly;

            if (next_ugly == next_multiple_of_2) {
                i2++;
                next_multiple_of_2 = ugly[i2] * 2;
            }
            if (next_ugly == next_multiple_of_3) {
                i3++;
                next_multiple_of_3 = ugly[i3] * 3;
            }
            if (next_ugly == next_multiple_of_5) {
                i5++;
                next_multiple_of_5 = ugly[i5] * 5;
            }
        }

        return ugly[n-1];
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int result = solution.nthUglyNumber(n);
    cout << "The " << n << "th ugly number is: " << result << endl;
    return 0;
}