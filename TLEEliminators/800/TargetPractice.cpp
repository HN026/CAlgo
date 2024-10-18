#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200007;
const int MOD = 1000000007;
 
int score[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,2,3,3,3,3,3,3,2,1},
	{1,2,3,4,4,4,4,3,2,1},
	{1,2,3,4,5,5,4,3,2,1},
	{1,2,3,4,5,5,4,3,2,1},
	{1,2,3,4,4,4,4,3,2,1},
	{1,2,3,3,3,3,3,3,2,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,1,1,1,1,1,1,1,1,1}
};
 
void solve() {
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			char c;
			cin >> c;
			if (c == 'X') {ans += score[i][j];}
		}
	}
	cout << ans << '\n';
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
}