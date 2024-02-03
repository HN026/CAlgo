#include <iostream>
#include <vector>

using namespace std;



bool search(vector<int> &nums, int k) {
  int n = nums.size();
  int s = 0;
  int e = nums.size() - 1;
  while (s <= e) {
    int mid = s + (e - s) / 2;

    if (nums[mid] == k)
      return true;

    if (nums[mid] == nums[s] && nums[mid] == nums[e]) {
      s++;
      e--;
      continue;
    }

    if (nums[s] <= nums[mid]) {
      if (nums[s] <= k && k <= nums[mid]) {
        e = mid - 1;
      } else {
        s = mid + 1;
      }
    } else {
      if (nums[mid] < k && k <= nums[e]) {
        s = mid + 1;
      } else {
        e = mid - 1;
      }
    }
  }
  return false;
}


int main() {
    vector<int> nums = {1, 0, 1, 1, 1};
    int target = 3;
    int result = search(nums, target);
    cout<<result<<endl;
}