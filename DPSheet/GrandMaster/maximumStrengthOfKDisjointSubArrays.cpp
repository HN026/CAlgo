#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

ll INF = 1e18;

long long maximumStrength(vector<int> &nums, int K) {
    int n = nums.size();
    vector<ll> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    }

    vector<ll> dp(2 * K + 1, -INF);
    dp[0] = 0;

    for (int i = n; i >= 0; i--) {
        vector<ll> curr(2 * K + 1, -INF);
        curr[0] = 0;
        for (int k = 1; k <= 2 * K; k++) {
            ll realK = (k + 1) / 2;
            ll sign = (realK % 2 == 0) ? 1 : -1;

            if (k % 2 == 0) {
                ll val = sign * realK * prefixSum[i];
                curr[k] = max(dp[k], val + dp[k - 1]);
            } else {
                sign *= -1;
                ll val = sign * realK * prefixSum[i];
                curr[k] = max(dp[k], val + curr[k - 1]);
            }
        }
        dp = curr;
    }

    return dp[2 * K];
}

int main() {
    vector<int> nums = {1, 2, 3, -1, 2};
    int k = 3;
    ll ans = maximumStrength(nums, k);
    cout << ans << endl;
    return 0;
}

// ********** 1. Maximum Strength of K Disjoint Subarrays *********
// *********Recursive Approach->BottomUp*********

// typedef long long int ll;

// ll INF = 1e18;

// class Solution {
// public:

//     long long solve(int index, int k, vector<vector<ll>> &dp,
//     vector<ll> &prefixSum, int n) {
//         if(k==0) return 0;
//         if(k<0 || index==n) return -INF;
//         if(dp[index][k]!=-1) return dp[index][k];

//         ll ans = solve(index+1, k, dp, prefixSum, n);
//         ll realK = (k+1)/2;
//         ll sign = (realK%2==0) ? 1 : -1;

//         // To check nonDashPart
//         if(k%2==0){
//             ll val = sign * realK * prefixSum[index];
//             ans = max(ans, val + solve(index+1, k-1, dp, prefixSum, n));
//         }
//         // To check DashPart
//         else{
//             sign *= -1;
//             ll val = sign * realK * prefixSum[index];
//             ans = max(ans, val + solve(index, k-1, dp, prefixSum, n));
//         }

//         dp[index][k] = ans;
//         return ans;
//     }

//     long long maximumStrength(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<ll> prefixSum(n+1, 0);
//         for(int i = 1; i<=n; i++){
//             prefixSum[i] = prefixSum[i-1] + nums[i-1];
//         }

//         vector<vector<ll>> dp(n+1, vector<ll> (2*k+1, -1));
//         return solve(0, 2*k, dp, prefixSum, n);
//     }
// };