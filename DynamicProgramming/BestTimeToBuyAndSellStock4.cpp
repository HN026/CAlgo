#include <bits/stdc++.h>

using namespace std;

int bestTime(vector<int> &prices){
    int n = prices.size();
    vector<int> dp(2, 0);

    int long long profit = 0;\
    for(int index = n-1; index>=0; index--){
        vector<int> curr(2, 0);
        for(int buyOrSell = 0; buyOrSell<=1; buyOrSell++){
            if(buyOrSell){
                // buy
                profit = max(-prices[index] + dp[0], 0 + dp[1]);
                curr[buyOrSell] = profit;
            }
            else{
                profit = max(prices[index] + dp[1], 0 + dp[0]);
                curr[buyOrSell] = profit;
            }
        }
        dp = curr;
    }

    return dp[1];
}

int main(){

    vector<int> prices = {7,1,5,3,6,4};

    int profit = bestTime(prices);
    cout<<profit<<endl;

    return 0;
}