#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));

    // Base cases all though not necessary because all values are already initialised to 0 but only writing for clearer

    // index == n
    for(int i = 0; i<2; i++){
        for(int j = 0; j<3; j++){
            dp[n][i][j] = 0;
        }
    }
    // trans == 0
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<2; j++){
            dp[i][j][0] = 0;
        }
    }

    for(int index = n-1; index>=0; index--){
        for(int buyOrSell = 0; buyOrSell<=1; buyOrSell++){
            for(int trans = 1; trans<=2; trans++){
                if(buyOrSell){
                    dp[index][buyOrSell][trans] = max(-prices[index] + dp[index+1][0][trans], 0 + dp[index+1][1][trans]);
                }
                else{
                    dp[index][buyOrSell][trans] = max(prices[index] + dp[index+1][1][trans-1], 0 + dp[index+1][0][trans]);
                }
            }
        }
    }

    return dp[0][1][2];
}

int main(){
    vector<int> prices = {3,3,5,0,0,3,1,4};

    int ans = maxProfit(prices);
    cout<<ans<<endl;

    return 0;
}