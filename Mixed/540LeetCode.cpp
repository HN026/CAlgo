#include<iostream>
#include<vector>

using namespace std;

int findSingleELement(vector<int> &nums){
    int s = 0;
    int e = nums.size()-1;

    while(s<e) {
        int mid = s + (e-s)/2;

        if (mid%2 != 0) {
            mid--;
        }

        if (nums[mid] != nums[mid+1]){
            e = mid;
        }
        else if (nums[mid] == nums[mid + 1]) {
            s = mid + 2;
        }
    }

    return s;
}

int main() {
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    int element = findSingleELement(nums);
    cout<<element<<endl;
    return 0;
}