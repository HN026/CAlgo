#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

class Solution {
    public:
        long long minimumOperations(vector<int> &nums, vector<int> &target){
            int n = nums.size();
            vector<int> diff(n);
            for(int i = 0; i<n; i++) diff[i] = target[i] - nums[i];
            
            ll ans = 0, incOp = 0, decOp = 0;
            for(int i = 0; i<n; i++){
                if(diff[i] > 0){
                    if(incOp < diff[i]) ans += diff[i] - incOp;
                    incOp = diff[i];
                    decOp = 0;
                }
                else if(diff[i] < 0){
                    if(decOp < -diff[i]) ans += -diff[i] - decOp;
                    decOp = -diff[i];
                    incOp = 0;
                }
                else{
                    incOp = decOp = 0;
                }
            }
            
            return ans;
        }
};

int main(){
    vector<int> nums = {3, 5, 1, 2};
    vector<int> target = {4,6,2,4};
    Solution sol;
    cout<<sol.minimumOperations(nums, target)<<endl;
    return 0;
}