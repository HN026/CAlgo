#include <iostream>
#include <vector>

using namespace std;

int mod = 1e9 + 7;

int evaluateExp(string &expression) {
  int n = expression.size();
  vector<vector<vector<long long int>>> dp(
      n, vector<vector<long long int>>(n, vector<long long int>(2, 0)));

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      if (i > j)
        continue;
      for (int isTrue = 0; isTrue < 2; isTrue++) {

        if (i == j) {
          if (isTrue == 1)
            dp[i][j][isTrue] = expression[i] == 'T';
          else
            dp[i][j][isTrue] = expression[i] == 'F';
          continue;
        }

        long long int ways = 0;
        for (int ind = i + 1; ind <= j - 1; ind += 2) {
          long long int lT = dp[i][ind - 1][1];
          long long int lF = dp[i][ind - 1][0];
          long long int rT = dp[ind + 1][j][1];
          long long int rF = dp[ind + 1][j][0];

          if (expression[ind] == '&') {
            if (isTrue)
              ways = (ways + (lT * rT) % mod) % mod;
            else
              ways =
                  (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) %
                  mod;
          } else if (expression[ind] == '|') {
            if (isTrue)
              ways =
                  (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) %
                  mod;
            else
              ways = (ways + (lF * rF) % mod) % mod;
          } else {
            if (isTrue)
              ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            else
              ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
          }
        }
        dp[i][j][isTrue] = ways;
      }
    }
  }
  return dp[0][n-1][1];
}

int main() {
  string exp = "F|T^F";
  int ans = evaluateExp(exp);
  cout << ans << endl;
  return 0;
}