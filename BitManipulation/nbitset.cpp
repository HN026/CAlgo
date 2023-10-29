#include <iostream>

using namespace std;

int main(){
    // TO check if n bit is set i.e if n bit is 1
    int n = 9; // 1001 we do numbering from LSB
    int k = 3;
    int mask = 1<<k; // 1000

    if(n & mask){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    
    
    return 0;
}