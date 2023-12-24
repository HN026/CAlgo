#include <bits/stdc++.h>

using namespace std;


int reverse32(int n){
    int ans = 0;
    int k = n;
    vector<int> V;
    int i = 0;
    while(k){
        V.push_back(k%10);
        k = k/10;
        i++;
    }
    if(i>=32) return 0;

    reverse(V.begin(), V.end());

    int r = 1;
    for(int j = 0; j<i; j++){
        ans = ans + V[j]*r;
        r = r*10;
    }

    return ans;
}


int main(){
    int n = 123;

    int ans = reverse32(n);
    cout<<ans<<endl;

    return 0;
}