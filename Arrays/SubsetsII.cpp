#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void makeSubsets(int index, vector<int> &k, vector<int> &nums, set<vector<int>> &st){
    if(index < 0){
        st.insert(k);
        return;
    }

    k.push_back(nums[index]);
    makeSubsets(index - 1, k, nums, st);
    k.pop_back();

    makeSubsets(index - 1, k, nums, st);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> st;
    vector<int> k;
    makeSubsets(n - 1, k, nums, st);

    vector<vector<int>> ans;
    for(auto it: st){
        ans.push_back(it);
    }

    return ans;
}

int main() {
    // Example usage
    vector<int> input = {1, 2, 2};
    vector<vector<int>> result = subsetsWithDup(input);

    // Displaying the result
    cout << "Subsets with Duplicates: " << endl;
    for (const auto& subset : result) {
        cout << "[ ";
        for (const auto& element : subset) {
            cout << element << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
