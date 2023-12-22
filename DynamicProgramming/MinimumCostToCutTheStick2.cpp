#include <bits/stdc++.h>

using namespace std;

int minCost(int m, int n, vector<int> &cuts){
    sort(cuts.begin(), cuts.end());
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    vector<vector<int>> dp(m+2, vector<int> (m+2, 0));

    for(int i = m; i>=1; i--){
        for(int j = 1; j<=m; j++){
            if(i>j) continue;
            int mini = 1e9;

            for(int k = i; k<=j; k++){
                int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][m];
}

int main(){
    vector<int> cuts = {5,6,1,4,2};
    int n = 9;
    int m = cuts.size();

    int ans = minCost(m, n, cuts);
    cout<<ans<<endl;

    return 0;
}