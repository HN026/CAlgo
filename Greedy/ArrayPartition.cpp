#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arrayPairSum(vector<int> &nums) {
  int n = nums.size();
  sort(nums.begin(), nums.end());
  int sum = 0;
  for (int i = 0; i < n; i = i + 2) {
    sum += nums[i];
  }
  return sum;
}

int main() {
  // Example usage of the arrayPairSum function
  vector<int> nums = {1, 4, 3, 2, 7, 6};

  int result = arrayPairSum(nums);

  cout << "Result: " << result << endl;

  return 0;
}
