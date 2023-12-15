#include <bits/stdc++.h>

using namespace std;

int bestTime(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int> (2, 0));
    //base case
    dp[n][0] = 0;
    dp[n][1] = 0;

    int long long profit = 0;
    for(int index = n-1; index>=0; index--){
        for(int buyOrSell = 0; buyOrSell<=1; buyOrSell++){
            if(buyOrSell){
                // buy
                profit = max(-prices[index] + dp[index+1][0], 0 + dp[index+1][1]);
                dp[index][buyOrSell] = profit;
            }
            else{
                profit = max(prices[index] + dp[index+1][1], 0 + dp[index+1][0]);
                dp[index][buyOrSell] = profit;
            }
        }
    }

    return dp[0][1];
}

int main(){

    vector<int> prices = {7,1,5,3,6,4};

    int profit = bestTime(prices);
    cout<<profit<<endl;

    return 0;
}