#include <iostream>
#include <stack>

using namespace std;

int maxWater(int height[], int n) {
    stack<int> st;
    int ans = 0;
    for(int i = 0; i<n; i++){
        while((!st.empty()) && (height[st.top()]<height[i])){
            int pop_height = height[st.top()];
            st.pop();

            if (st.empty()){
                break;
            }

            int distance = i - st.top() -1;
            int min_height = min(height[st.top()], height[i]) - pop_height;
            ans += distance * min_height;
        }
        st.push(i);
    }
    return ans;
}

int main() {
    int arr[] = {3,0,2,0,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxWater(arr,n)<<endl;
    return 0;
}