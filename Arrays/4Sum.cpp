#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target) {
  sort(nums.begin(), nums.end());
  int n = nums.size();
  set<vector<int>> st;
  for (int i = 0; i < n - 3; i++) {
    for (int j = i + 1; j < n - 2; j++) {
      int e = n - 1;
      int s = j + 1;
      while (s < e) {
        long long int sum =
            static_cast<long long>(nums[i]) + static_cast<long long>(nums[j]) +
            static_cast<long long>(nums[s]) + static_cast<long long>(nums[e]);
        if (sum == target) {
          st.insert({nums[i], nums[j], nums[s], nums[e]});
          s++;
          e--;
        } else if (sum > target) {
          e--;
        } else {
          s++;
        }
      }
    }
  }

  return {st.begin(), st.end()};
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = fourSum(nums, target);

    cout << "Quadruplets with sum equal to " << target << " are:" << endl;
    for (const auto &quadruplet : result) {
        for (int num : quadruplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}