#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool rabin_karp_search(string &text, string &pattern) {
    const int prime = 31;
    const int MOD = 1e9 + 9;
    int n = text.size();
    int m = pattern.size();

    vector<long long> p_pow(max(n, m));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++) {
        p_pow[i] = (p_pow[i - 1] * prime) % MOD;
    }

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] + (text[i] - 'a' + 1) * p_pow[i]) % MOD;
    }

    long long h_pattern = 0;
    for (int i = 0; i < m; i++) {
        h_pattern = (h_pattern + (pattern[i] - 'a' + 1) * p_pow[i]) % MOD;
    }

    vector<int> occurences;
    for (int i = 0; i <= n - m; i++) {
        long long cur_h = (h[m + i] + MOD - h[i]) % MOD;
        if (cur_h == h_pattern * p_pow[i] % MOD) {
            occurences.push_back(i);
        }
    }

    return occurences.size()!=0;
}

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();

        string s = a;
        int i = 1;
        while(s.size() < m){
            s += a;
            i++;
        }
        if(rabin_karp_search(s, b)) return i;
        s += a;
        return rabin_karp_search(s, b) ? i + 1 : -1;
    }
};

int main() {
    string a = "abcd";
    string b = "cdabcdab";

    Solution solution;
    int result = solution.repeatedStringMatch(a, b);
    cout << "Minimum number of times string a has to be repeated: " << result << endl;

    return 0;
}