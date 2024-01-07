#include <iostream>

using namespace std;

int main(){
    long long int N;
    cin>>N;
    while(N>1){
        cout<<N<<" ";
        if(N&1) N = 3*N+1;
        else N >>=1;
    }
    cout<<1<<endl;
}