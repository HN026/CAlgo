#include <iostream>
#include <limits.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    if(n==0) return tasks.size();
    unordered_map<char, int> mp;
    int m = tasks.size();
    int maxi = INT_MIN;
    for(int i = 0; i<m; i++){
        mp[tasks[i]] += 1;
        maxi = max(maxi, mp[tasks[i]]);
    }
    
    int cnt = 0;
    for(auto it: mp){
        if(it.second==maxi){
            cnt++;
        }
    }

    int ans = (maxi - 1)*(n+1) + cnt;
    return max(ans, m);
}

int main() {
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    int result = leastInterval(tasks, n);
    cout<<result<<endl;
    return 0;
}