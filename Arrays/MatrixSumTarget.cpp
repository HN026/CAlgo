#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int> nums, int target){
    int n = nums.size();
    int preSum = 0;
    int cnt = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for(int i = 0; i<n; i++){
        preSum += nums[i];
        int remove = preSum - target;
        cnt += mp[remove];
        mp[preSum] += 1;
    }
    return cnt;
}

int numberOfMatrixSum(vector<vector<int>> nums, int target){
    int cnt = 0;
    int n = nums.size();
    int m = nums[0].size();

    for(int i = 0; i<n; i++){
        vector<int> row(m, 0);
        for(int j = i; j<n; j++){
            for(int k = 0; k<m; k++){
                row[k] += nums[j][k];
            }
            cnt += subarraySum(row, target);
        }
    }
    return cnt;
}


int main(){
    vector<vector<int>> nums = {
            {0, 1, 0},
            {1, 1, 1},
            {0, 1, 0},
    };

    int ans = numberOfMatrixSum(nums, 0);
    cout<<ans<<endl;

    return 0;
}