#include <iostream>
#include <vector>

using namespace std;

int minInArray(vector<int> &nums){
    int n = nums.size();
    int start = 0;
    int end = n-1;

    while(start<=end){
        int mid = start + (end-start)/2;

        if(nums[mid]>=nums[start]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }

    return nums[start];
}

int main(){

    vector<int> nums = {4,5,6,7,0,1,2};

    int result = minInArray(nums);
    cout<<result<<endl;

    return 0;
}