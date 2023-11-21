#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int minTriangle(vector<vector<int>> &triangle){
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int> (n, -1));

    for(int i = 0; i<n; i++){
        dp[n-1][i] = triangle[n-1][i];
    }

    for(int j=n-2; j>=0; j--){
        for(int k = j; k>=0; k--){
            int down = INT_MAX;
            int diagonal = INT_MAX;
            if(j+1<n) down = triangle[j][k] + dp[j+1][k];
            if(j+1<n && k+1<n) diagonal = triangle[j][k] + dp[j+1][k+1];
            dp[j][k] = min(down, diagonal);
        }
    }

    return dp[0][0];
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