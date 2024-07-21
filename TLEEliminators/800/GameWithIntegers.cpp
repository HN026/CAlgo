#include <iostream>

using namespace std;

void gameWithIntegers(int n){
    if(n%3) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        gameWithIntegers(n);
    }
    return 0;
}