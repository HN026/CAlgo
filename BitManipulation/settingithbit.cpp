#include <iostream>

using namespace std;

int main(){
    // Means to set the kth bit to 1
    int n = 13; //001101
    int k = 4;
    int mask = 1<<k;
    int ans = n|mask;
    cout<<ans;
    return 0;
}