#include<iostream>
#include<vector>

using namespace std;

int LongestSubArrayK(vector<int>arr, int K){
    int left = 0;
    int current_sum = 0;
    int max_length = 0;

    for(int right = 0; right<arr.size(); ++right){
        current_sum += arr[right];

        while(current_sum >= K){
            current_sum -= arr[left];
            left++;
        }

        if(current_sum == K){
            max_length = max(max_length, right-left + 1);
        }
    }

    return max_length;
}


int main() {
    vector<int> arr = {1,2,3,1,1,1,1};
    int K = 3;
    int result = LongestSubArrayK(arr, K);
    cout<<"Length of the longest subarray with sum K is: "<<result<<endl;
    return 0;
}