#include <iostream>
#include <unordered_map>
#include <limits.h>
using namespace std;

string minWindow(string s, string t){
    int n = s.size();
    int m = t.size();
    if(m>n) return "";
    unordered_map<char, int> mp;
    for(int i = 0; i<m; i++){
        mp[t[i]] += 1;
    }
    int count = mp.size();
    int minLength = INT_MAX;
    int minStart = 0;
    int left = 0;

    for(int right = 0; right<n; right++){
        if(mp.find(s[right])!=mp.end()){
           mp[s[right]] -= 1;
           if(mp[s[right]]==0){
                count--;
           } 
        }

        while(count==0){
            if(right-left+1<minLength){
                minLength = right-left+1;
                minStart = left;
            }

            if(mp.find(s[left])!=mp.end()){
                if(mp[s[left]]==0){
                    count++;
                }
                mp[s[left]] += 1;
            }
            left++;
        }
    }

    if(minLength==INT_MAX) return "";
    return s.substr(minStart, minLength);
}

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";

    string ans = minWindow(s, t);
    cout<<ans<<endl;

    return 0;
}