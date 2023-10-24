#include <iostream>
#include <vector>

using namespace std;

bool isPossible(vector<int> &time, int n, int m , int mid){
    int hours = 0;
    int days = 1;
    for(int i = 0; i<m; i++){
        if(hours + time[i] <= mid) hours += time[i];
        else{
            days++;
            if(days>n||time[i]>mid){
                return false;
            }
            hours = 0;
            hours += time[i];
        }
    }
    return true;
}


int BookAllocation(vector<int> &time, int n, int m){
    if(n>m) return -1;
    int sum = 0;
    int maxTime = 0;
    for(auto it: time){
        sum += it;
        maxTime = max(it, maxTime);
    }
    int s = maxTime;
    int e = sum;
    int mid = s + (e-s)/2;
    int ans = sum;
    while(s<=e){
        if(isPossible(time,n,m,mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}


int main(){

    int m = 7;
    int n = 4;
    vector<int> a = {2,2,3,3,4,4,1};

    cout<<BookAllocation(a,n,m);

    return 0;
}