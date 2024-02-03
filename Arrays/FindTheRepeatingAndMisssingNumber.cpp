#include <iostream>
#include <vector>

using namespace std;

pair<int,int> missingandrepeating(vector<int> &nums){
    int n = nums.size();
    int xr = 0;
    for(int i = 0; i<n; i++){
        xr = xr ^ nums[i];
        xr = xr ^ (i+1);
    }

    int bitNumber = 0;
    while(true){
        if(xr & (1<<bitNumber) !=0 ){
            break;
        }
        bitNumber++;
    }

    int zero = 0;
    int one = 0;

    for(int i = 0; i<n; i++){
        if(nums[i]&(1<<bitNumber) != 0){
            one = one ^ nums[i];
        }
        else{
            zero = zero ^ nums[i];   
        }
    }

    for(int i = 1; i<=n; i++){
        if(i & (1<bitNumber) != 0){
            one = one ^ i;
        }
        else{
            zero = zero ^ i;
        }
    }

    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(nums[i]==zero) cnt++;
    }

    if(cnt==2) return {zero, one};

    return {one, zero};
}

int main(){
    vector<int> nums = {3,1,2,5,4,6,7,5};
    
    pair<int,int> p = missingandrepeating(nums);
    cout<<p.first<<endl;
    cout<<p.second<<endl;

    return 0;
}