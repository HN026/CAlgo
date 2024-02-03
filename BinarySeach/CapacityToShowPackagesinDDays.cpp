#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int dayCount(vector<int> &weights, int maxWeight) {
  int daycnt = 1;
  int weightTotal = 0;
  for (int i = 0; i < weights.size(); i++) {
    if (weightTotal + weights[i] <= maxWeight) {
      weightTotal += weights[i];
    } else {
      daycnt++;
      weightTotal = weights[i];
    }
  }
  return daycnt;
}

int shipWithinDays(vector<int> &weights, int days) {
  int n = weights.size();
  int low = INT_MIN;
  int high = 0;
  for (int i = 0; i < n; i++) {
    low = max(low, weights[i]);
    high += weights[i];
  }

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (dayCount(weights, mid) > days) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return low;
}

int main() {
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    int result = shipWithinDays(weights, days);
    cout << "The minimum ship capacity is: " << result << endl;
    return 0;
}