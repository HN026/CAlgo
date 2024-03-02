#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    pair<int, int> NumOfZerosOnes(string &s) {
        int n = s.size();
        int zero = 0;
        int one = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                zero++;
            if (s[i] == '1')
                one++;
        }
        return {zero, one};
    }

    int findMaxForm(vector<string> &strs, int m, int n) {
        int k = strs.size();
        vector<vector<vector<int>>> dp(k, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        pair<int, int> p = NumOfZerosOnes(strs[0]);

        for (int i = p.first; i <= m; i++) {
            for (int j = p.second; j <= n; j++) {
                dp[0][i][j] = 1;
            }
        }

        for (int index = 1; index < k; index++) {
            pair<int, int> z = NumOfZerosOnes(strs[index]);
            int zeros = z.first;
            int ones = z.second;
            for (int zero = 0; zero <= m; zero++) {
                for (int one = 0; one <= n; one++) {
                    int notTake = dp[index - 1][zero][one];
                    int take = INT_MIN;
                    if (zeros <= zero && ones <= one)
                        take = 1 + dp[index - 1][zero - zeros][one - ones];
                    dp[index][zero][one] = max(notTake, take);
                }
            }
        }

        return dp[k - 1][m][n];
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5;
    int n = 3;
    int result = solution.findMaxForm(strs, m, n);
    cout << "The maximum number of strings that can be formed with " << m << " zeros and " << n << " ones is: " << result << endl;
    return 0;
}