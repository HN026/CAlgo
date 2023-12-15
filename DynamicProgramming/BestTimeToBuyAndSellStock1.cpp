// The intuition is if you're selling on the ith day then you will have to buy it on any of the 0 to i-1 days and
// for profit to be maximum you will have to buy it on the day when the price is minimum and sell it on the day.
// You can only buy and sell once.


#include <bits/stdc++.h>

using namespace std;

int bestTime(vector<int> &prices){
    int mini = prices[0];    
    int maxProfit = 0;

    int n = prices.size();

    for(int i = 1; i<n; i++){
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]);
    }

    return maxProfit;
}

int main(){
    vector<int> prices = {2, 100, 150, 120};

    int minPrices = bestTime(prices);
    cout<<minPrices<<endl;

    return 0;
}