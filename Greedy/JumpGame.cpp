#include <iostream>
#include <vector>

using namespace std;

int jumpGame(vector<int> &nums){
    int reach = 0;
    int i;
    for(i = 0; i<nums.size() && i<=reach; i++){
        reach = max(reach, i+nums[i]);
    }

    return i==nums.size();
}

int main(){
    vector<int> nums = {2,3,1,1,4};
    int ans = jumpGame(nums);
    cout<<ans<<endl;
    return 0;
}