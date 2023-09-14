#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> firstNegative(vector<int> A, int n, int k){
    deque<int> dq;
    vector<int> ans;
    
    // for first k elements
    for(int i = 0; i<k; i++){
        if(A[i]<0){
            dq.push_back(i);
        }
    }

    if(dq.size()>0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }

    // for the remaining windows
    for(int i = k; i<n; i++){
        if(!dq.empty() && i-dq.front()>=k){
            dq.pop_front();
        }

        if(A[i]<0){
            dq.push_back(i);
        }

        if(!dq.empty()){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
return ans;
}




int main() {
    vector<int> A = {5,-3,-2,3,-4};
    firstNegative(A, 5, 2);

    return 0;
}