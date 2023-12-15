// Max Transactions that can be done are 2.
// We will be using 3D DP for this. 

#include <bits/stdc++.h>

using namespace std;

int f(int index, int buyOrSell, vector<vector<vector<int>>> &dp, vector<int> &prices, int trans){

    if(!trans || index == prices.size()) return 0;

    if(dp[index][buyOrSell][trans]!=-1) return dp[index][buyOrSell][trans];

    long long int profit = 0;

    if(buyOrSell){
        profit = max(-prices[index] + f(index+1, 0, dp, prices, trans), 0 + f(index+1, 1, dp, prices, trans));
    } 
    else{
        profit = max(prices[index] + f(index+1, 1, dp, prices, trans-1), 0 + f(index+1, 0, dp, prices, trans));
    }

    return dp[index][buyOrSell][trans] = profit;
}


int maxProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int> (3, -1)));
    int allowedTransactions = 2;
    return f(0, 1, dp, prices, allowedTransactions);
}

int main(){
    vector<int> prices = {3,3,5,0,0,3,1,4};

    int ans = maxProfit(prices);
    cout<<ans<<endl;

    return 0;
}