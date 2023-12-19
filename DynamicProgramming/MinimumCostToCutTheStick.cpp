#include <bits/stdc++.h>

using namespace std;

int f(int i, int j, vector<vector<int>> &dp, vector<int> &cuts){
    if(i>j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int mini = 1e9;

    for(int index = i; index<=j; index++){
        int cost = cuts[j+1] - cuts[i-1] + f(i, index-1, dp, cuts) + f(index+1, j, dp, cuts);
        mini = min(mini, cost);
    }

    return dp[i][j] = mini;
}



int minCost(int m, int n, vector<int> &cuts){
    sort(cuts.begin(), cuts.end());
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    vector<vector<int>> dp(m+1, vector<int> (m+1, -1));
    return f(1, m, dp, cuts);
}

int main(){
    vector<int> cuts = {5,6,1,4,2};
    int n = 9;
    int m = cuts.size();

    int ans = minCost(m, n, cuts);
    cout<<ans<<endl;

    return 0;
}