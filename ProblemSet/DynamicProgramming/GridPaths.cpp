#include <iostream>

using namespace std;

long long int mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    int dp[n+1][n+1];
    int c[n+1][n+1];
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            char k;
            cin>>k;
            if(k=='.') c[i][j] = 0;
            else c[i][j] = 1;
        }
    }

    for(int i = n; i>=1; i--){
        for(int j = n; j>=1; j--){
            if(i==n && j==n) dp[i][j] = 1;
            else{
                int w1 = (j==n) ? 0 : dp[i][j+1];
                int w2 = (i==n) ? 0 : dp[i+1][j];
                dp[i][j] = (w1+w2)%mod;
                if(c[i][j]) dp[i][j] = 0;
            }
        }
    }
    
    if(c[n][n]!=1) cout<<dp[1][1];
    else cout<<0;
    
    return 0;
}