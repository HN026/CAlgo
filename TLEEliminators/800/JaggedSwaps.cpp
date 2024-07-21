#include <iostream>
#include <algorithm>

using namespace std;

bool JaggedSwaps(int n, int *a){
    if(is_sorted(a, a+n)) return true;
    
    bool check = false;
    
    do{
        check = false;
        for(int i = 1; i<n-1; i++){
            if(a[i] > a[i-1] && a[i] > a[i+1]){
                swap(a[i], a[i+1]);
                check = true;
            }
        }
        if(check==false) return false;
    } while(!is_sorted(a, a+n) && check);
    
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
        bool ans = JaggedSwaps(n, a);
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    
    return 0;
}