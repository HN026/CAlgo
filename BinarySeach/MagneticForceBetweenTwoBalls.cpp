#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int> &position, int force, int m) {
  int ballCount = 1;
  int lastPosition = position[0];

  for (int i = 1; i < position.size(); i++) {
    if (position[i] - lastPosition >= force) {
      ballCount++;
      lastPosition = position[i];
    }

    if (ballCount >= m)
      return true;
  }
  return false;
}

int maxDistance(vector<int> &position, int m) {
  sort(position.begin(), position.end());
  int n = position.size();
  int low = 1;
  int high = position[n - 1] - position[0];

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (isPossible(position, mid, m)) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return high;
}

int main() {
    vector<int> position = {1,2,3,4,7,9};
    int m = 3;
    int result = maxDistance(position, m);
    cout << "The maximum minimum distance is: " << result << endl;
    return 0;
}