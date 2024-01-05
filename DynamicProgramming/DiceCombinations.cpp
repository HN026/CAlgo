#include <iostream>
#include <vector>

using namespace std;

int diceCombinations(int n){
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=6; j++){
            if(j>i){
                break;
            }
            else{
                dp[i] += dp[i-j];
            }
        }
    }
    return dp[n];
}


int main(){
    int n = 3;
    int ans = diceCombinations(n);
    cout<<ans<<endl;
    return 0;
}