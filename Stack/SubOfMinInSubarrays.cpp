#include <iostream>
#include <vector>
#include <stack>

int mod = 1e9+7;

/*https://leetcode.com/problems/sum-of-subarray-minimums/solutions/4595335/beats-100-c-java-python-js-explained-with-video-monotonic-stack/?envType=daily-question&envId=2024-01-20*/
// Refer to this solution for better understanding.

using namespace std;

int Sum(vector<int> &nums){
    int n = nums.size();
    vector<int> left(n, -1); // Left index can be from 0
    vector<int> right(n, n); // right index can be from n
    stack<int> st;

    for(int i = 0; i<n; i++){
        while(!st.empty() && nums[i]<=nums[st.top()]){
            st.pop();
        } 
        if(!st.empty()){
            left[i] = st.top();
        }
        st.push(i);
    }

    st = stack<int>();

    for(int i = n-1; i>=0; i--){
        while(!st.empty() && nums[i]<nums[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            right[i] = st.top();
        }
        st.push(i);;
    }

    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += (i - left[i])*(right[i] - i)*nums[i]%mod;
        sum %= mod;
    }

    return sum;
}


int main(){

    vector<int> nums = {3, 1, 2, 4};

    int ans = Sum(nums);
    cout<<ans<<endl;

    return 0;
}