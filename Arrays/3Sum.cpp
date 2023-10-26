#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> ThreeSum(vector<int> arr, int target, int n){
    set<vector<int>> st;
    sort(arr.begin(), arr.end());
    for(int i = 0; i<n; i++){
        int s = i+1;
        int e = n-1;
        while(s<=e){
            if(arr[i]+arr[s]+arr[e]==target){
                st.insert({arr[i], arr[s], arr[e]});
                s++;
                e--;
            }
            else if(arr[i]+arr[s]+arr[e]>target){
                e--;
            }
            else{
                s++;
            }
        }
    }
    vector<vector<int>> ans;
    for (auto it: st){
        ans.push_back(it);
    }
    return ans;
}

int main(){

    vector<int> arr = {10,5,5,5,2};
    int target = 12;
    int n = arr.size();

    vector<vector<int>> ans = ThreeSum(arr, target, n);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}