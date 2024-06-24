#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0) return {0};
        vector<int> dp(n+1, 0);
        dp[0] = 0, dp[1] = 1;
        for(int i = 2; i<=n; i++) dp[i] = (i%2==0) ? dp[i/2] : dp[i/2] + 1;
        return dp;
    }
};

int main() {
    Solution s;
    vector<int> res = s.countBits(5);
    for(int i = 0; i<res.size(); i++) cout << res[i] << " ";
    cout << endl;
    return 0;
}