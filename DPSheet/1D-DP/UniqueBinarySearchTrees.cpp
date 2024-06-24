#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i<=n; i++){
            for(int j = 1; j<=i; j++){
                int left = dp[j-1]; 
                int right = dp[i-j];
                dp[i] += left * right;
            }
        }

        return dp[n];
    }
};

// j is the root, j-1 number of ways in the left substree and i-j are the number of ways in the right subtree.

int main(){
    Solution s;
    cout << s.numTrees(3) << endl;
    return 0;
}