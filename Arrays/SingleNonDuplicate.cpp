#include <bits/stdc++.h>

using namespace std;

int singleNonDuplicate(vector<int> arr){
    int s = 0;
    int e = arr.size()-1;

    while(s<e){
        int mid = s + (e-s)/2;
        if(mid%2==1) mid--;
        if(arr[mid]!=arr[mid+1]) e = mid;
        else s = mid + 2;
    }
    return arr[s];
}



int main(){
    vector<int> arr = {1,1,2,2,3,4,4,5,5};
    int ans = singleNonDuplicate(arr);
    cout<<ans<<endl;
    return 0;
}