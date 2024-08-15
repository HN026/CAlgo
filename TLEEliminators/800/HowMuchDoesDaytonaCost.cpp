#include <iostream>
#include <vector>

using namespace std;

bool daytonaCost(int n, vector<int> &a, int k){
    for(int i = 0; i<n; i++) if(a[i]==k) return true;
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];
        bool ans = daytonaCost(n, a, k);
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}