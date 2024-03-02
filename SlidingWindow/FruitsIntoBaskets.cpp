#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int totalFruit(vector<int> &fruits) {
        int n = fruits.size();
        int left = 0;
        int cnt = 0;
        unordered_map<int, int> mp;
        for (int right = 0; right < n; right++) {
            mp[fruits[right]]++;

            while (mp.size() > 2) {
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }
                left++;
            }

            cnt = max(cnt, right - left + 1);
        }

        return cnt;
    }
};

int main() {
    Solution solution;
    vector<int> fruits = {1, 2, 1, 2, 2};
    int result = solution.totalFruit(fruits);
    cout << "The maximum number of fruits you can collect is: " << result << endl;
    return 0;
}