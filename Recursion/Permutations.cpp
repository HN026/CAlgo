#include <vector>
#include <iostream>
using namespace std;

void permutations(int index, vector<int> &nums, vector<vector<int>> &ans){
    if(index==nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i = index; i<nums.size(); i++){
        swap(nums[index], nums[i]);
        permutations(index+1, nums, ans);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    permutations(0, nums, ans);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permute(nums);

    // Print the permutations
    for (const auto &v : ans) {
        for (int num : v) {
            cout << num << ' ';
        }
        cout << '\n';
    }

    return 0;
}