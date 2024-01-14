#include <iostream>
#include <unordered_map>

using namespace std;
    int minSteps(string s, string t) {
        int n = s.size();

        unordered_map<char, int> mp;
        for(int i = 0; i<n; i++) mp[s[i]] += 1;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(mp[t[i]]==0) cnt++;
            else mp[t[i]]--;
        }

        return cnt;
    }

int main(){
    string s = "leetcode";
    string t = "practice";

    int ans = minSteps(s, t);
    cout<<ans<<endl;

    return 0;
}