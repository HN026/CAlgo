#include <iostream>
#include <vector>
#include <stack> 

using namespace std;


vector<int> NextGreaterElement(vector<int> &A){
    int n = A.size();
    vector<int> B(n);
    stack<int> st;
    st.push(-1);

    for(int i = n-1; i>=0; i--){
        while(st.top()!=-1 && A[i]>st.top()){
            st.pop();
        }
        B[i] = st.top();
        st.push(A[i]);        
    }

    return B;
}



int main(){

    vector<int> A = {};

    vector<int> ans = NextGreaterElement(A);

    for(auto it: ans) cout<<it<<" ";

    return 0;
}