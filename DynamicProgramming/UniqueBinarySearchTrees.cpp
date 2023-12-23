#include <iostream>
#include <vector>

using namespace std;


int f(int n, vector<int> &dp){
    if(n==0 || n==1){
        return 1;
    }
    if(dp[n]!=-1) return dp[n];
    int ans = 0;

    for(int i = 1; i<=n; i++){
        int left = f(i-1, dp);
        int right = f(n-i, dp);
        ans += left*right;
    }

    return dp[n] = ans;
}


int uniqueBSTs(int n){
    if(n==0 || n==1){
        return 1;
    }
    vector<int> dp(n+1, -1);
    return f(n, dp);
}



int main(){
    int n = 5;
    int ans = uniqueBSTs(n);
    cout<<ans<<endl;
    return 0;
}