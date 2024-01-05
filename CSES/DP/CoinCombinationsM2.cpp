/*https://cses.fi/problemset/task/1635*/

#include <iostream>
#include <vector>

using namespace std;

int Ways(vector<int> &nums, int target){
    vector<int> dp(target+1, 0);
    dp[0] = 1;
    for(int i = 1; i<=target; i++){
        for(int j = 0; j<nums.size(); j++){
            if(nums[j]<=i){
                dp[i] = dp[i] + dp[i-nums[j]];
            }
        }
    }
    return dp[target];
}


int main(){
    vector<int> nums = {2,3,5};
    int target = 9;
    int ans = Ways(nums, target);
    cout<<ans<<endl;
    return 0;
}