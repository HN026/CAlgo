#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int minTriangle(vector<vector<int>> &triangle){
    int n = triangle.size();
    vector<int> dp(n, -1); 

    for(int i = 0; i<n; i++){
        dp[i] = triangle[n-1][i];
    }
    for(int j = n-2; j>=0; j--){
        vector<int> curr(n, -1);
            for(int k = j; k>=0; k--){
                int down = INT_MAX;
                int diagonal = INT_MAX;

                if(j+1<n) down = triangle[j][k] +  dp[k];
                if(j+1<n && k+1<n) diagonal = triangle[j][k] + dp[k+1];
                curr[k] = min(down, diagonal);
            }
        dp = curr;
    }
    return dp[0];
}

int main(){
    vector<vector<int>> triangle {
        {1},
        {2,3},
        {3,6,7},
        {8,9,6,10},
    };

    int ans = minTriangle(triangle);
    cout<<ans<<endl;
    return 0;
}