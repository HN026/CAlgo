#include <iostream>
#include <set>
#include <string>

using namespace std;

int goodSubstring(string &a, string &b, int k) {
    int badCount = 0, left = 0;
    set<string> st;
    int n = a.size();
    for (int right = 0; right < n; ++right) {
        if (b[a[right] - 'a'] == '0') badCount++;
        while (badCount > k) {
            if (b[a[left] - 'a'] == '0') badCount--;
            left++;
        }
        for (int i = left; i <= right; ++i) {
            st.insert(a.substr(i, right - i + 1));
        }
    }
    return st.size();
}

int main() {
    string a, b;
    int k;
    cin >> a >> b >> k;
    cout << goodSubstring(a, b, k) << endl;
    return 0;
}
