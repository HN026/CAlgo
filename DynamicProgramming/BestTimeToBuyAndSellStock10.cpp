// We will be having transaction fee for each transaction

#include <bits/stdc++.h>

using namespace std;

int bestTime(vector<int> &prices, int fee){
    int n = prices.size();
    vector<int> dp(2, 0);
    
    for(int index = n-1; index>=0; index--){
        vector<int> curr(2, 0);
        for(int buyOrSell = 0; buyOrSell<=1; buyOrSell++){
            if(buyOrSell){
                curr[buyOrSell] = max(-prices[index] + dp[0], 0 + dp[1]);
            }
            else{
                curr[buyOrSell] = max(prices[index] + dp[1] - fee, 0 + dp[0]);
            }
        }
        dp = curr;
    }

    return dp[1];
}

int main(){

    vector<int> prices = {1,3,2,8,4,9};

    int profit = bestTime(prices, 2);
    cout<<profit<<endl;

    return 0;
}