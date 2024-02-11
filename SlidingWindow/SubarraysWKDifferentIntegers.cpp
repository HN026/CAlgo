#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int atMost(vector<int> &nums, int k) {
  int n = nums.size();
  int left = 0;
  int cnt = 0;
  unordered_map<int, int> mp;
  for (int right = 0; right < n; right++) {
    if (mp.find(nums[right]) == mp.end()) {
      k--;
    }
    mp[nums[right]] += 1;
    while (k < 0) {
      mp[nums[left]]--;
      if (mp[nums[left]] == 0) {
        mp.erase(nums[left]);
        k++;
      }
      left++;
    }
    cnt += right - left + 1;
  }
  return cnt;
}

int subarraysWithKDistinct(vector<int> &nums, int k) {
  return atMost(nums, k) - atMost(nums, k - 1);
}

int main() {
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;

    int result = subarraysWithKDistinct(nums, k);

    cout << "The number of subarrays with exactly " << k << " distinct integers is " << result << endl;

    return 0;
}