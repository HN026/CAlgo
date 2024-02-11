#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int numSquares(int n){
    vector<int> dp(n+1, 0);
    for(int i = 0; i<=n; i++){
        dp[i] = i;
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j*j<=i; j++){
            int notTake = dp[i];
            int take = 1 + dp[i - j*j];
            dp[i] = min(take, notTake);
        }
    }
    return dp[n];
}



int main(){
    int n = 3;
    int result = numSquares(n);
    cout<<result<<endl;
    return 0;
}