#include <iostream>
#include <vector>

using namespace std;

// TC : O(m*n)
// SC : O(n)

// Temp represents same row and dp represents previour row in Space optimization.

int countWays(int m, int n){
    vector<int> dp(n, 0);
    for(int i = 0; i<m; i++){
        vector<int> temp(n, 0);
        for(int j = 0; j<n; j++){
            if(i==0&&j==0){
                temp[j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;

            if(i>0) up = dp[j]; // Previous row 
            if(j>0) left = temp[j-1]; // same row

            temp[j] = up + left;    
        }
        dp = temp;
    }
    return dp[n-1];
}


int main(){
    int m = 3;
    int n = 2;

    cout<<"Number of unique ways will be: "<<countWays(m, n)<<endl;
    return 0;
}