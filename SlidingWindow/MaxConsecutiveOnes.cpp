#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int total(vector<int> &nums, int k) {
  int n = nums.size();
  int left = 0;
  int mx = 0;
  for (int right = 0; right < n; right++) {
    if (!nums[right])
      k -= 1;
    while (k < 0) {
      if (!nums[left])
        k += 1;
      left += 1;
    }
    mx = max(mx, right - left + 1);
  }
  return mx;
}

int main() {
  vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
  int k = 3;
  int ans = total(nums, k);
  cout << ans << endl;

  return 0;
}