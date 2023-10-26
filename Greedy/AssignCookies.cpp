#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool compare(int a, int b){
    return a>b;
}

int AssignCookies(vector<int> &greed, vector<int> &sz){
    sort(greed.begin(), greed.end(), compare);
    sort(sz.begin(), sz.end(), compare);
    int i = 0;
    int j = 0;
    int count = 0;
    while(i<greed.size() && j<sz.size()){
        if(greed[i]<=sz[j]){
            count++;
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    return count;
}

int main(){
    vector<int> greed = {3,5,6,4};
    vector<int> sz = {1,4,5};

    cout<<AssignCookies(greed, sz)<<endl;
    return 0;
}