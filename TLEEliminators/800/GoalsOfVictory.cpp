#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n-1; i++) cin >> a[i];

        long long posSum = 0;
        long long negSum = 0;

        for(int i = 0; i < n-1; i++) {
            if(a[i] > 0) posSum += a[i];
            else negSum += a[i];
        }

        if(posSum == -negSum) {
            cout << 0 << endl;
        } else if(posSum > -negSum) {
            int ans = posSum + negSum; 
            cout << -ans << endl;
        } else {
            int ans = -negSum - posSum;
            cout << ans << endl;
        }
    }

    return 0;
}
