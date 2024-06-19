#include <iostream>

using namespace std;

int main(){
    int x = 0;
    int n;
    cin>>n;
    string a = "";
    while(n){
        cin>>a;
        if(a=="X++") x++;
        else if(a=="X--") x--;
        else if(a=="++X") ++x;
        else --x;
        n--;
    }
    cout<<x;
    return 0;
}