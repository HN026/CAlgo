#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int minSwaps(vector<int> &nums) {
        int n = nums.size();

        int k = 0;
        for (int i = 0; i < n; i++)
            if (nums[i] == 1)
                k++;
        if (!k)
            return 0;

        int currZeros = 0;
        int ans = INT_MAX;
        int left = 0;

        for (int right = 0; right < n + k; right++) {
            if (nums[right % n] == 0)
                currZeros++;

            while (right - left + 1 == k) {
                ans = min(currZeros, ans);
                if (nums[left % n] == 0)
                    currZeros--;
                left++;
            }
        }

        return ans;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> nums(N);
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
        }

        Solution sol;
        int result = sol.minSwaps(nums);
        cout << result << endl;
    }

    return 0;
}