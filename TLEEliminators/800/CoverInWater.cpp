#include <iostream>

using namespace std;

int coverInWater(int n, string &s){
    int e = 0;
    bool flag = false;
    for(int i = 0; i<n; i++){
        if(s[i]=='.') e++;
        if(i>0 && i<n-1 && s[i-1]=='.' && s[i]=='.' && s[i+1]=='.') {
            flag = true;
            break;
        }
    }
    return flag ? 2 : e;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        int ans = coverInWater(n, s);
        cout<<ans<<endl;
    }
    return 0;
}