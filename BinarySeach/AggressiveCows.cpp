#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int k){
    int cntCows = 1;
    int lastStall = stalls[0];
    int n = stalls.size();
    for(int i = 1; i<n; i++){
        if(stalls[i]-lastStall>=dist){
            cntCows++;
            lastStall = stalls[i];
        }
        if(cntCows==k) return true;
    }
    return false;
}


int aggressiveCows(vector<int>&stalls, int k){
   sort(stalls.begin(), stalls.end());
   int n = stalls.size();
   int low = 1;
   int high = stalls[n-1] - stalls[0]; // Let's assume there are only two cows.

//    high Impossible
//    low Possible  Solution will be returning high since polarity will change.
   while(low<=high){
        int mid = low + (high-low)/2;

        if(canWePlace(stalls, mid, k)){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
   }

   return high; 
}

int main(){
    vector<int> stalls = {0,3,4,7,10,9};
    int k = 4;
    cout<<aggressiveCows(stalls, k)<<endl;
    return 0;
}