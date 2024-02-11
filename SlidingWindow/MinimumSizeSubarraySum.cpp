#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int minSubArrayLen(int target, vector<int> &nums) {
  int n = nums.size();
  int left = 0;
  int minLength = INT_MAX;

  for (int right = 0; right < n; right++) {
    target -= nums[right];

    while (target <= 0) {
      minLength = min(minLength, right - left + 1);
      target += nums[left];
      left++;
    }
  }
  if (minLength == INT_MAX)
    return 0;
  return minLength;
}

int main() {
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;

    int result = minSubArrayLen(target, nums);

    cout << "The minimum length of a contiguous subarray with a sum at least " << target << " is " << result << endl;

    return 0;
}