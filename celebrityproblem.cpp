#include<iostream>
#include<stack>
#include<vector>

using namespace std;

bool knows(vector<vector<int>> &M, int a, int b, int n) {
    if(M[a][b] == 1) {
        return true;
    }
    return false;
}


int Celebrity(vector<vector<int>> &M, int n){
    stack<int> s;
    for(int i = 0; i<n; i++){
        s.push(i);
    }

    while (s.size() != 1) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if(knows(M, a, b, n)){
            s.push(b);
        }
        else if (knows(M, a, b, n)){
            s.push(a);
        }
    }
    int candidate = -1;
    if(!s.empty()){
    candidate = s.top();
    }

    int zeroCount = 0;
    bool zero = false;
    for(int i = 0; i<n; i++) {
        if(M[candidate][i] == 0){
            zeroCount++;
        }
    }
   
    if(zeroCount == n) {
        zero = true;
    }

    int oneCount = 0;
    bool one = false;
    for(int i = 0; i<n; i++){
        if(M[i][candidate] == 1){
            oneCount++;
        }
    }

    if(oneCount==n-1){
        one = true;
    }

    if(one == true && zero == true) {
        return candidate;
    }
    return -1;
}




int main(){

    vector<vector<int>> M = {{0,1,0}, {0,0,0}, {0,1,0}};
    int n = M.size();

    int k = Celebrity(M, n);

    cout<<k<<endl;
    
    return 0;
}