// You can buy and sell more than once but make sure you will always sell before buying again.
// 1 -> can buy cannot sell
// 0 -> can't buy has to sell
// Time Complexity - O(n*2)

#include <bits/stdc++.h>

using namespace std;

int f(int index, int buyOrSell, vector<vector<int>> &dp, vector<int> &prices){
    if( index >= prices.size() ) return 0;
    if(dp[index][buyOrSell] != -1) return dp[index][buyOrSell];
    int long long profit = 0;
    if(buyOrSell){
        // buy
        profit = max(-prices[index] + f(index+1, 0, dp, prices), 0 + f(index+1, 1, dp, prices));
    }
    else{
        // sell
        profit = max(prices[index] + f(index+1, 1, dp, prices), 0 + f(index+1, 0, dp, prices));
    }

    return dp[index][buyOrSell] = profit;
}

int bestTime(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int> (2, -1));
    return f(0, 1, dp, prices);
}

int main(){

    vector<int> prices = {7,1,5,3,6,4};

    int profit = bestTime(prices);
    cout<<profit<<endl;

    return 0;
}