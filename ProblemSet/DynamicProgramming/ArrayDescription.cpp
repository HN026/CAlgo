#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9+7;

int solve(int n, int m, vector<int> &v){
    vector<vector<int>> dp(n, vector<int>(m+1, 0));

    for(int i = 0; i<n; i++){
        for(int x = 1; x<=m; x++){
            if (i==0){
                if(v[i]==0 || v[i]==x) dp[i][x] = 1;
                else dp[i][x] = 0;
            }
            else{
                if(v[i]==0 || v[i]==x){
                    dp[i][x] = ((dp[i-1][x-1] + dp[i-1][x])%mod + dp[i-1][x+1])%mod; 
                } 
                else dp[i][x] = 0;
            }
        }
    }

    int ans = 0;
    for(int x = 1; x<=m; x++){
        ans = (ans + dp[n-1][x])%mod;
    }
    return ans;
}


int main(){
    int n, m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    cout<<solve(n, m, v)<<endl;
    return 0;
}