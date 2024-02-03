#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int countStudents(vector<int> &nums, int pagesAllowed){
    int studentCount = 1;
    int pagesTotal = 0;
    for(int i = 0; i<nums.size(); i++){
        if(pagesTotal + nums[i] <= pagesAllowed){
            pagesTotal += nums[i];
        }
        else{
            studentCount++;
            pagesTotal = nums[i];
        }
    }
    return studentCount;
}

int BookAllocation(vector<int> &nums, int n, int m){
    if(m>n) return -1;
    int maxi = INT_MIN;
    int sum = 0;
    for(int i = 0; i<n; i++){
        maxi = max(maxi, nums[i]);
        sum += nums[i];
    }

    int low = maxi;
    int high = sum;

    while(low<=high){
        int mid = low + (high-low)/2;
        int Students = countStudents(nums, mid);
        if(Students>m){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}

int main()
{
    int n = 5;
    int m = 4;
    vector<int> a = {25,46,28,49,24};

    cout<<BookAllocation(a,n,m);

    return 0;
}