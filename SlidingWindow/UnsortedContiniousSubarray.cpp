#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
    vector<int> temp(nums.begin(), nums.end());
    sort(temp.begin(), temp.end());
    int n = nums.size();
    int s = 0;
    int e = n-1;
    while(s < n && nums[s]==temp[s]) s++;
    while(e > s && nums[e]==temp[e]) e--;
    return e-s+1;
}

int main() {
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    int result = findUnsortedSubarray(nums);
    cout << "Length of the shortest unsorted subarray: " << result << endl;
    return 0;
}