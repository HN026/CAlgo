#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int countTriplets(vector<int> &arr) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i] ^ arr[i];
        }
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int k = i + 1; k < n; k++) {
                if (dp[i] == dp[k + 1])
                    count += (k - i);
            }
        }
        return count;
    }
};

int main() {
    vector<int> arr = {2, 3, 1, 6, 7};

    Solution sol = Solution();
    int ans = sol.countTriplets(arr);
    cout << ans << endl;
    return 0;
}