#include <iostream>
#include <string>

using namespace std;

int dontTryToCount(string &x, string &s){
    int count = 0;
    int n = s.size();
    while(x.size() < s.size()){
        count++;
        x += x;
    }
    if(x.find(s)!=string::npos) return count;
    x += x;
    count++;
    if(x.find(s)!=string::npos) return count;    
    return  -1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string x, s;
        cin>>x>>s;
        int ans = dontTryToCount(x, s);
        cout<<ans<<endl;
    }
    return 0;
}