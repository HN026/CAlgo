#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int dp[n+1];
    dp[0] = 0;
    for(int i = 1; i<=n; i++){
        int temp = i;
        int minSteps = 1e9;
        while(temp){
            int di = temp%10;
            temp = temp/10;
            if(di==0) continue;
            minSteps = min(minSteps, 1 + dp[i - di]);
        }
        dp[i] = minSteps;
    }
    cout<<dp[n]<<endl;
    return 0;
}