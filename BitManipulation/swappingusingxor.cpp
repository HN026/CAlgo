#include <iostream>

using namespace std;

int main(){
    int a = 5;
    int b = 7;

    // 5^7
    a = a^b;
    // 5^7^7
    b = a^b;
    a = a^b;

    cout<<a<<" "<<b;

    return 0;
}