#include <iostream>
#include <vector>

using namespace std;

int validParentheses(string s){
    int n = s.length();
    vector<int> dp(n, 0);
    dp[0] = 0; // Base case as it doesnt matter if the first one is ( or )
    int answer = 0;

    for(int i = 1; i<n; i++){
        if(s[i]=='('){
            dp[i] = 0;
        }
        else{
            if(s[i-1]=='('){
                if(i-2>=0){
                    dp[i] = dp[i-2] + 2;
                }
                else{
                    dp[i] = 2;
                }
            }
            else{
                if(i - dp[i-1] - 1 >=0 && s[i-dp[i-1]-1]== '('){
                    dp[i] = dp[i-1] + 2;
                    if(i-dp[i-1]-2>=0){
                        dp[i] += dp[i-dp[i-1]-2];
                    }
                }
            }
        }
        answer = max(answer, dp[i]);
    }
    return answer;
}



int main(){
    string s = ")()())";
    int ans = validParentheses(s);
    cout<<ans<<endl;
    return 0;
}