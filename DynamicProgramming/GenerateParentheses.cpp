#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(string op, int open, int close, vector<string> &ans, vector<vector<vector<string>>> &dp) {
  if (open == 0 && close == 0) {
    ans.push_back(op);
    dp[open][close].push_back(op);
    return;
  }

  if(dp[open][close].size()!=0){
        for(auto s: dp[open][close]){
            ans.push_back(s);
        }
        return;
  }

  if (open == close) {
    string op1 = op;
    op1.push_back('(');
    solve(op1, open - 1, close, ans, dp);
  } else if (open == 0) {
    string op1 = op;
    op1.push_back(')');
    solve(op1, open, close - 1, ans, dp);
  } else if (close == 0) {
    string op1 = op;
    op1.push_back('(');
    solve(op1, open - 1, close, ans, dp);
  } else {
    string op1 = op;
    string op2 = op;
    op1.push_back('(');
    op2.push_back(')');
    solve(op1, open - 1, close, ans, dp);
    solve(op2, open, close - 1, ans, dp);
  }
}

vector<string> genParentheses(int n) {
  vector<string> ans;
  if (n == 0)
    return ans;

  vector<vector<vector<string>>> dp(n+1, vector<vector<string>> (n+1));  
  solve("", n, n, ans, dp);


  return ans;
}

int main() {
  int n = 3;
  vector<string> ans = genParentheses(n);
  for (auto s : ans) {
    cout << s << endl;
  }
  return 0;
}