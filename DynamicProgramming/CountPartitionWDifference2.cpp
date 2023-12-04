#include <bits/stdc++.h>

using namespace std;

int f(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (arr[0] != 0 && arr[0] <= target)
        dp[0][arr[0]] = 1;
    for (int index = 1; index < n; index++)
    {
        for (int tar = 0; tar <= target; tar++)
        {
            int notTake = dp[index - 1][tar];
            int take = 0;
            if (arr[index] <= tar)
                take = dp[index - 1][tar - arr[index]];
            dp[index][tar] = take + notTake; 
        }
    }
    return dp[n - 1][target];
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