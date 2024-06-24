#include <iostream>

using namespace std;

// The only element that can be the sum of all other elements is the maximum element, since all elements are positive. Therefore, for each prefix i from 1 to n, check if sum(a1,a2,...,ai)−max(a1,a2,...,ai)=max(a1,a2,...,ai). The sum and max of prefixes can be tracked with variables outside the loop.

int main() {
    int t;
    cin>>t;
    while(t){
        int n;
        cin>>n; 
        int a[n];
        for(int i = 0; i<n; i++) cin>>a[i];
        
        long long int sum = 0;
        int mx = -1e9, cnt = 0;
        
        for(int i = 0; i<n; i++){
            sum += a[i];
            mx = max(mx, a[i]);
            if(sum - mx == mx) cnt++;
        }
        
        cout<<cnt<<endl;
        t--;
    }
    return 0;
}