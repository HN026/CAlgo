#include <iostream>
#include <vector>

using namespace std;

int f(vector<int> arr){
    int n = arr.size();
    vector<int> dp(n, -1);
    dp[0] = arr[0];
    for(int i = 1; i<n; i++){
        int pick = arr[i];
        if(i>1) pick += dp[i-2];
        int nonpick = dp[i-1];
        dp[i] = max(pick,nonpick);
    }
    return dp[n-1];
}

int robStreet(int n, vector<int> &arr){
    vector<int> arr2;
    if(n==1) return arr[0];
    for(int i = 1; i<n; i++){
        arr2.push_back(arr[i]);
    }
    arr.pop_back();
    int ans1 = f(arr);
    int ans2 = f(arr2);

    return max(ans1, ans2);
}

int main(){
    vector<int> arr{1,5,1,2,6};
    int n = arr.size();
    cout<<robStreet(n, arr);
    return 0;
}