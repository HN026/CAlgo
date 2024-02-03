#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007; // You can adjust the modulo value as needed

int kInversePairs(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int relpairs = 0; relpairs < i; relpairs++) {
                if (j - relpairs >= 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - relpairs]) % MOD;
                }
            }
        }
    }

    return dp[n][k];
}


int main() {
    int n, k;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Enter the value of k: ";
    cin >> k;

    int result = kInversePairs(n, k);

    cout << "Number of arrays with " << k << " inverse pairs: " << result << endl;

    return 0;
}

