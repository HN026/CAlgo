#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool check(string s){
    int n = s.length();
    string ans = "";

    for(int i = 0; i<n; i++){
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A' && s[i]<='Z') || (s[i]>='0'&&s[i]<='9')){
            if(s[i]>='A' && s[i]<='Z'){
                s[i] += 32;
                ans += s[i];
            }
            else{
                ans+=s[i];
            }
        }
    }
    int f = 0;
    int e = ans.size()-1;
    while(f<e){
        if(ans[f]!=ans[e]){
            return false;
        }
        f++;
        e--;
    }
    return true;
}




int main(){
    string s = "A1b22Ba";
    cout<<check(s)<<endl;
    return 0;
}