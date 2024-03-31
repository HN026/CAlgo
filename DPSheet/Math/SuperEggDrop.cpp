#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp(101, vector<int>(10001, -1));

class Solution {
  public:
    int superEggDrop(int k, int n) {
        if (n == 1 || n == 0)
            return n;
        if (k == 1)
            return n;

        if (dp[k][n] != -1)
            return dp[k][n];
        int low = 1, high = n;
        while (low < high) {
            int floor = low + (high - low) / 2;
            int break_case = superEggDrop(k - 1, floor - 1);
            int not_break_case = superEggDrop(k, n - floor);
            if (break_case < not_break_case) {
                low = floor + 1;
            } else {
                high = floor;
            }
        }
        return dp[k][n] = 1 + max(superEggDrop(k - 1, low - 1), superEggDrop(k, n - low));
    }
};

int main() {
    Solution sol;
    int k = 2;
    int n = 6;
    int result = sol.superEggDrop(k, n);
    cout << "The minimum number of attempts in the worst case with " << k << " eggs and " << n << " floors is: " << result << endl;
    return 0;
}

// Basically, this is a min-max problem
// Low initally will be pointing at the not break case and high will be pointing at the break case hence at the end of the BS, polarity will be reversed and low will be pointing at the breakcase
// The `superEggDrop` function is using a dynamic programming approach combined with binary search to find the minimum number of steps.

// The function is based on the following idea: for a given number of eggs `k` and a number of floors `n`, we can drop an egg from a floor `f` (where `f` is between `1` and `n`). There are two possibilities:

// 1. The egg breaks: In this case, we know the critical floor must be below `f`, so we are left with `k-1` eggs and `f-1` floors to check, which we denote as `superEggDrop(k-1, f-1)`.

// 2. The egg doesn't break: In this case, we know the critical floor must be above `f`, so we still have `k` eggs but only `n-f` floors to check, which we denote as `superEggDrop(k, n-f)`.

// The worst-case scenario is the maximum of these two possibilities, and we add `1` to this because we have made a drop.

// We want to minimize this worst-case scenario, so for each floor `f`, we calculate this value and return the minimum result.

// In each scenario, we're interested in the maximum number of attempts because we want to be prepared for the worst outcome. If we prepared for the best outcome (i.e., the egg never breaks), we could end up breaking all our eggs without finding the critical floor.

// The binary search is used to optimize the process of finding the floor `f` that gives the minimum worst-case scenario. Instead of checking every floor from `1` to `n`, we use binary search to quickly find the optimal floor `f`. The condition for the binary search is based on comparing `superEggDrop(k-1, mid-1)` and `superEggDrop(k, n-mid)`. If the former is less than the latter, it means the worst-case scenario is more likely to be in the upper floors, so we adjust the lower bound of the binary search. Otherwise, we adjust the upper bound.