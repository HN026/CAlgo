#include <iostream>
#include <unordered_map>

using namespace std;

bool doremysPaint3(int n, int* a){
    unordered_map<int, int> mp;
    for(int i = 0; i<n; i++){
        mp[a[i]]++;
        if(mp.size() > 2) return false;
    }

    if(mp.size() == 2){
        int it = mp.begin()->second;
        if(it != n/2 && it!=(n+1)/2) return false;
    }

    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0; i<n; i++) cin>>a[i];
        bool ans = doremysPaint3(n, a);
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}