#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int> &height) {
  int n = height.size();
  vector<int> left(n);
  vector<int> right(n);
  int water = 0;
  left[0] = height[0];
  for (int i = 1; i < n; i++) {
    left[i] = max(left[i - 1], height[i]);
  }
  right[n - 1] = height[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    right[i] = max(right[i + 1], height[i]);
  }

  for (int i = 1; i < n; i++) {
    int var = min(left[i], right[i]);
    if (var > height[i]) {
      water += var - height[i];
    }
  }

  return water;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = trap(height);
    cout << "The total amount of rain water trapped is: " << result << endl;
    return 0;
}