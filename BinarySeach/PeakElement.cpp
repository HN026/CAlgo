#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int findPeakElement(vector<int>& nums) {
    if(nums.size()==1) return 0;
    int n = nums.size();
    int s = 0;
    int e = n-1;
    int ans = 0;
    while(s<=e){
        int mid = s + (e-s)/2;
        long long int minpl = INT_MIN;
        long long int minpu = INT_MIN;
        if(mid+1<n) minpu = (int)nums[mid+1];
        if(mid-1>=0) minpl = (int)nums[mid-1];

        if(nums[mid]>minpl && nums[mid]>minpu){
            ans = mid;
            return mid;
        }
        else if(nums[mid]<minpu){
            s = mid + 1;
        }
        else if(minpl>nums[mid]){
            e = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 1};
    cout << findPeakElement(nums1) << endl;

    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    cout << findPeakElement(nums2) << endl;

    vector<int> nums3 = {1, 2, 3, 4, 5};
    cout << findPeakElement(nums3) << endl;

    vector<int> nums4 = {5, 4, 3, 2, 1};
    cout << findPeakElement(nums4) << endl;

    return 0;
}
