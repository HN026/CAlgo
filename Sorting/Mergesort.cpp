#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &nums, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left<=mid && right<=high){
        if(nums[left]<=nums[right]){
            temp.push_back(nums[left++]);
        }
        else{
            temp.push_back(nums[right++]);
        }
    }

    while(left<=mid){
        temp.push_back(nums[left++]);
    }
    while(right<=high){
        temp.push_back(nums[right++]);
    }

    for(int i =  low; i<=high; i++){
        nums[i] = temp[i-low];
    }

}

void mergeSort(vector<int> &nums, int low, int high){
    if(low>=high){
        return;
    }
    int mid = low + (high-low)/2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid+1, high);
    merge(nums, low, mid, high);
}

int main(){

    vector<int> nums = {5,4,3,2,1};

    cout<<"Before Merge Sort: "<<endl;
    for(auto it: nums){
        cout<<it<<" ";
    }
    cout<<endl;
    int n = nums.size();
    int s = 0;
    int e = n-1;
    mergeSort(nums, s, e);

    cout<<"After Merge Sort"<<endl;
    for(auto it: nums){
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
}