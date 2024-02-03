#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, m;
    cin>>n>>m;
    vector<int> prices(n+1, 0);
    vector<int> pages(n+1, 0);
    
    for(int i = 1; i<=n;i++) cin>>prices[i];
    for(int i = 1; i<=n;i++) cin>>pages[i];

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for(int i = 1; i<=n; i++){
        for(int money = 0; money<=m; money++){
            if(money==0) dp[i][money] = 0;
            else {
                int notTake = (i==1) ? 0 : dp[i-1][money];
                int take = (money<prices[i]) ? 0 : pages[i] + dp[i-1][money-prices[i]];
                dp[i][money] = max(notTake, take);
            }
        } 
    }
    
    cout<<dp[n][m];

    return 0;
}