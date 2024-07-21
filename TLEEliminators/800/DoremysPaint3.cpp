#include <iostream>

using namespace std;

bool doremysPaint3(int n, int* a){
    if(n==2) return true;
    
    return false;
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