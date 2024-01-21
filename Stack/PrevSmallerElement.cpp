#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> prevSmallerElement(vector<int> &arr){
    int n = arr.size();
    vector<int> B(n);
    stack<int> st;
    st.push(-1);

    for(int i = 0; i<n; i++){
        while(st.top()!=-1 && arr[i]<st.top()){
            st.pop();
        }
        B[i] = st.top();
        st.push(arr[i]);
    }

    return B;
}
 

int main(){

    vector<int> arr = {3, 1, 2, 4, 1, 6};
    vector<int> ans = prevSmallerElement(arr);
    for(auto it: ans) cout<<it<<" ";
    return 0;
}