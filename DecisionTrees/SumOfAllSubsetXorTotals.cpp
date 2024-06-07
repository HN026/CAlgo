#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void calSum(int index, int tempSum, int &sum, int n, vector<int> &nums) {
        if (index == n)
            return;

        // Include
        tempSum ^= nums[index];
        sum += tempSum;
        calSum(index + 1, tempSum, sum, n, nums);
        tempSum ^= nums[index];

        // Exclude
        calSum(index + 1, tempSum, sum, n, nums);
    }

    int subsetXORSum(vector<int> &nums) {
        int n = nums.size();
        int sum = 0;
        int tempSum = 0;
        calSum(0, tempSum, sum, n, nums);
        return sum;
    }
};

int main() {
    vector<int> nums = {1, 3, 5};
    Solution s;
    cout << "The XOR sum of all subsets of nums is: " << s.subsetXORSum(nums) << endl;

    return 0;
}