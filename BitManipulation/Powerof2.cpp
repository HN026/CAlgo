#include <iostream>

using namespace std;

int main(){
    int n = 1;
    if((n&(n-1))==0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}