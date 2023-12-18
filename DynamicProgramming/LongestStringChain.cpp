#include <bits/stdc++.h>

using namespace std;

bool compare(string &a, string &b){
    return a.length()<b.length();
}

bool isPossible(string &a, string &b){
    int n = a.length();
    int m = b.length();

    // second is pointing on the bigger string
    // first is pointing on the smaller string

    if(n+1!=m){
        return false;
    }

    int first = 0;
    int second = 0;

    while(second < m){
        if(a[first]==b[second]){
            first++;
            second++;
        }
        else{
            second++;
        }
    }

    if(first==n && second==m) return true;
    return false;
}



int longestStrChain(vector<string> &words){
    int n = words.size();
    vector<int> dp(n, 1);

    sort(words.begin(), words.end(), compare);

    int maxi = 1;

    for(int index = 0; index<n; index++){
        for(int prev = 0; prev<index; prev++){
            if(isPossible(words[prev], words[index]) && dp[index]<dp[prev]+1){
                dp[index] = dp[prev] + 1;
            }
        }
        maxi = max(maxi, dp[index]);
    }
    return maxi;
}

int main(){
    vector<string> words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};

    int ans = longestStrChain(words);
    cout<<ans<<endl;

    return 0;
}