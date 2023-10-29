#include <iostream>

using namespace std;

int XO(int n){
    if(n%4==0) return n;
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    return 0;
}
int main(){   
    int a = XO(4);
    int b = XO(6);
    int c = a^b;
    cout<<c<<endl;
    return 0;
}