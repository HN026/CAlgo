#include <bits/stdc++.h>

using namespace std;

int maxProfit(int k, vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> after(2, vector<int> (k+1, 0));
    vector<vector<int>> curr(2, vector<int> (k+1, 0));

    for(int index = n-1; index>=0; index--){
        for(int buyOrSell = 0; buyOrSell<=1; buyOrSell++){
            for(int trans = 1; trans<=k; trans++){
                if(buyOrSell){
                    curr[buyOrSell][trans] = max(-prices[index] + after[0][trans], 0 + after[1][trans]);
                }
                else{
                    curr[buyOrSell][trans] = max(prices[index] + after[1][trans-1], 0 + after[0][trans]);
                }
            }
        }
        after = curr;
    }
    return after[1][k];
}

int main(){
    vector<int> prices = {2,4,1};

    int ans = maxProfit(2, prices);
    cout<<ans<<endl;

    return 0;
}