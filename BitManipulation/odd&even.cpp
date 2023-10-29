#include <iostream>

using namespace std;

int main(){
    
    // In even numbers, the last bit is not set while
    // as in odd numbers the last bit is set

    int N = 4;
    if(N & 1 == 0){
        cout<<"Even"<<endl;
    }
    else{
        cout<<"Odd"<<endl;
    }

    return 0;
}