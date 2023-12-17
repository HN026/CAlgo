#include <bits/stdc++.h>

using namespace std;

int lemonadeChange(vector<int> &change){
    int n = change.size();
    unordered_map<int, int> hash;

    for(auto it: change){
        if(it==5){
            hash[5]++;
        }
        else if(it==10){
            if(hash[5]<=0){
                return false;
            }
            hash[5]--;
            hash[10]++;
        }
        else{ // $20
            if(hash[10]>0 && hash[5]>0){
                hash[10]--;
                hash[5]--;
            }
            else if(hash[5]>=3){
                hash[5] -= 3;
            }
            else{
                return false;
            }
            hash[20]++;
        }
    }
    return true;
}

int main(){
    vector<int> change = {5,5,5,10,20};
    int ans = lemonadeChange(change);
    cout<<ans<<endl;
    return 0;
}