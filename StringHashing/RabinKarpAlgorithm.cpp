// Article Link: https://cp-algorithms.com/string/rabin-karp.html
// Important Points: Hash[s[i...j]] = (Hash[s[0...j]] - Hash[s[0...i-1]])%MOD
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> rabin_karp_search(string &text, string &pattern) {
    const int prime = 31;
    const int MOD = 1e9 + 9;
    int n = text.size();
    int m = pattern.size();

    // Precomputing all the powers of p.
    vector<long long> p_pow(max(n, m));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++) {
        p_pow[i] = (p_pow[i - 1] * prime) % MOD;
    }

    // Hashing all the prefixes of the text.
    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] + (text[i] - 'a' + 1) * p_pow[i]) % MOD;
    }

    // Hashing the pattern.
    long long h_pattern = 0;
    for (int i = 0; i < m; i++) {
        h_pattern = (h_pattern + (pattern[i] - 'a' + 1) * p_pow[i]) % MOD;
    }

    // Searching for the pattern in the text
    vector<int> occurences;
    for (int i = 0; i <= n - m; i++) {
        long long cur_h = (h[m + i] + MOD - h[i]) % MOD; // MOD is added to ensure result is positive, as h[m+i] - h[i] can be negative.
        if (cur_h == h_pattern * p_pow[i] % MOD) {       // This step is being done for adjusting the power of p.
            occurences.push_back(i);
        }
    }

    return occurences;
}

int main() {
    string text = "abacabaaaabaasdfaabaabasdlfkjasdlkfabaabaasfjsdafabaseaba";
    string pattern = "aba";

    vector<int> occurences = rabin_karp_search(text, pattern);
    for (auto it : occurences) {
        cout << it << endl;
    }
    return 0;
}