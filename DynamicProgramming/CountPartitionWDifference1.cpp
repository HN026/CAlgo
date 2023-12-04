#include <iostream>
#include <vector>

using namespace std;

// arr[i]>=0

int mod = (int)(1e9 + 7);

int solve(int index, int target, vector<vector<int>> &dp, vector<int> &arr)
{
    if (index == 0)
    {
        if (target == 0 && arr[index] == 0)
            return 2;
        if (target == 0 || arr[index] == target)
            return 1;
        return 0;
    }
    if (dp[index][target] != -1)
        return dp[index][target];

    int notTake = solve(index - 1, target, dp, arr);
    int take = 0;
    if (arr[index] <= target)
        take = solve(index - 1, target - arr[index], dp, arr);
    return dp[index][target] = (take + notTake) % mod;
}

int f(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return solve(n - 1, target, dp, arr);
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int totalSum = 0;
    for (auto it : arr)
        totalSum += it;
    if (totalSum - d < 0 || (totalSum - d) % 2)
        return 0;
    return f(arr, (totalSum - d) / 2);
}

int main()
{
    vector<int> arr = {5, 2, 5, 1};
    int n = arr.size();
    int D = 3;
    int ans = countPartitions(n, D, arr);
    cout << ans << endl;
    return 0;
}