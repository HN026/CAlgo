#include <iostream>
#include <vector>

using namespace std;

bool interleavingStrings(string s1, string s2, string s3){
    int n1 = s1.size();
    int n2 = s2.size();
    int n3 = s3.size();
    if(n1 + n2 != n3) return false;

    vector<bool> dp(n2+1, 0);

    for(int i = 0; i<=n1; i++){
        vector<bool> curr(n2+1,0);
        for(int j = 0; j<=n2; j++){
            if(i==0 && j==0) curr[j] = true;
            else if(i>0 && j>0 && s1[i-1]==s3[i+j-1] && s2[j-1]==s3[i+j-1]){
                curr[j] = dp[j] || curr[j-1];
            }
            else if(i>0 && s1[i-1]==s3[i+j-1]) curr[j] = dp[j];
            else if(j>0 && s2[j-1]==s3[i+j-1]) curr[j] = curr[j-1];
        }
        dp = curr;
    }
    return dp[n2];
}

int main(){
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";

    bool ans = interleavingStrings(s1,s2,s3);
    cout<<ans<<endl;
    return 0;
}