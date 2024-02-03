#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> sequentialDigits(int low, int high){
    queue<long long unsigned int> q;
    for(int i = 1; i<=9; i++) q.push(i);
    vector<int> ans;
    while(true){
        long long unsigned int n = q.front();
        q.pop();
        if(n > high) break;
        if(low<=n && n<=high) ans.push_back(n);

        long long unsigned int ones = n%10;
        if (ones<9) {
            q.push(n*10 + (ones+1));
        }
    }
    return ans;
}

int main(){

    int low = 1000;
    int high = 13000;

    vector<int> ans = sequentialDigits(low, high);
    for(auto it: ans) cout<<it<<" ";
    cout<<endl;

    return 0;
}