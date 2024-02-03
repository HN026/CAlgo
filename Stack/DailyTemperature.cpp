#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> maxTemp(vector<int> &nums){
    int n = nums.size();
    vector<int> ans(n, 0);
    stack<int> st;
    for(int i = n-1; i>=0; i--){
        while(!st.empty() && nums[i]>=nums[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top() - i;
        }
        st.push(i);
    }

    return ans;
}

int main(){
    vector<int> nums = {73,74,75,71,69,72,76,73};
    vector<int> ans = maxTemp(nums);
    for(auto it: ans) cout<<it<<" ";
    return 0;
}