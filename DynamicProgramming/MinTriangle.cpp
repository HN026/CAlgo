#include <bits/stdc++.h>

using namespace std;

int f(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &triangle, int n){
    if(i==n-1) return triangle[i][j];
    if(dp[i][j]!=-1) return dp[i][j];

    int down = INT_MAX;
    int diagonal = INT_MAX;

    if(i+1<n) down = triangle[i][j] + f(i+1, j, dp, triangle, n);
    if(i+1<n && j+1<n) diagonal = triangle[i][j] + f(i+1, j+1, dp, triangle, n);

    return dp[i][j] = min(down, diagonal);
}

int minTriangle(vector<vector<int>> &triangle){
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int> (n, -1));
    return f(0,0, dp, triangle, n);
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