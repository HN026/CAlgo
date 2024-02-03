#include <iostream>

using namespace std;

int charToNum(char a){
    if(a>='A' && a<='Z'){
        return int(a - 'A');
    }
    return (int)(a -'a');
}

bool comp(char a, char b){
    int n1 = charToNum(a);
    int n2 = charToNum(b);
    return n1==n2;
}


int keyChanges(string s){
    int n = s.size();
    int cnt = 0;
    for(int i = 1; i<n; i++){
        if(!comp(s[i-1], s[i])) cnt++;
    }
    return cnt;
}

int main(){
    string s = "aAbBcC";
    
    int ans = keyChanges(s);
    cout<<ans<<endl;
    return 0;
}