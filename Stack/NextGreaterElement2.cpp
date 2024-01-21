#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    
    for(int i = n-1; i>=0; i--){
        st.push(nums[i]);
    }
    
    vector<int> result(n, -1);
    
    for(int i = n-1; i>=0; i--){
        while(!st.empty() && nums[i]>=st.top()){
            st.pop();
        }
        
        if(!st.empty()){
            result[i] = st.top();
        }
        
        st.push(nums[i]);
    }
    
    return result;
}

int main() {
    vector<int> nums = {1, 2, 1};
    vector<int> result = nextGreaterElements(nums);

    cout << "Next greater elements: ";
    for (int val : result) {
        cout << val << " ";
    }
    
    return 0;
}
