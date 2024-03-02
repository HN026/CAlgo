#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int findLength(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    int m = nums2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLength = INT_MIN;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (nums1[i - 1] == nums2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0;
            maxLength = max(maxLength, dp[i][j]);
        }
    }

    return maxLength;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};
    int result = findLength(nums1, nums2);
    cout << "The length of the longest common subarray is: " << result << endl;
    return 0;
}