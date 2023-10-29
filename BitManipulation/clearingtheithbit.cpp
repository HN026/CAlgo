#include <iostream>

using namespace std; 

int main(){
    int n = 50; // 110010
    int k = 4; 
    int mask = 1<<k;
    mask = ~mask;
    int ans = mask&n;
    cout<<ans<<endl;
    return 0;
}