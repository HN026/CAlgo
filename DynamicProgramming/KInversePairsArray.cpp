#include <iostream>
#include <vector>

using namespace std;

int MOD = 1e9+7;
// This solution will give TLE on Leetcode.
int count(int n, int k, vector<vector<int>> &solve){
    if(n==0){
        if(k==0) return 1;
        else return 0;
    }
    if(k<0) return 1;

    if(solve[n][k]!=-1) return solve[n][k];
    int res = 0;
    for(int i = 0; i<n; i++){
        res = (res + count(n-1, k-i, solve))%MOD;
    }
    return solve[n][k] = res%MOD;
}


int kInversePairs(int n, int k){
    vector<vector<int>> solve(n+1, vector<int> (k+1, -1));
    return count(n, k, solve);
}

int main(){
    int n = 3;
    int k = 1;

    int ans = kInversePairs(n, k);
    cout<<ans<<endl;

    return 0;
}