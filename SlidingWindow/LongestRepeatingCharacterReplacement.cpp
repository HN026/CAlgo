#include <iostream>
#include <unordered_map>
#include <limits.h>

using namespace std;

int maxCount(unordered_map<char, int> &mp){
    int cnt = 0;
    for(auto it: mp){
        cnt = max(cnt, it.second);
    }
    return cnt;
}

int maxConv(string s, int k){
    unordered_map<char, int> mp;
    int mx, left = 0;
    int n = s.size();
    for(int right = 0; right<n; right++){
        mp[s[right]] += 1;

        while(right-left+1 - maxCount(mp) > k) {
            mp[s[left]] -= 1;
            left ++;
        }

        mx = max(mx, right-left+1);
    }
    return mx;
}




int main(){
    string s = "AABABBA";
    int k = 1;

    int ans = maxConv(s, k);
    cout<<ans<<endl;

    return 0;
}