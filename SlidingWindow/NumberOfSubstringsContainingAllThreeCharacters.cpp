#include <iostream>

using namespace std;

int numberOfSubstrings(string s) {
  int n = s.size();
  int index_a = -1;
  int index_b = -1;
  int index_c = -1;
  int count = 0;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'a')
      index_a = i;
    if (s[i] == 'b')
      index_b = i;
    if (s[i] == 'c')
      index_c = i;

    if (i >= 2) {
      count += min(index_a, min(index_b, index_c)) + 1;
    }
  }

  return count;
}

int main() {
  string s = "abcabc";

  int ans = numberOfSubstrings(s);
  cout << ans << endl;

  return 0;
}