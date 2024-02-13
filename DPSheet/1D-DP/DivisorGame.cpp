#include <iostream>

using namespace std;

bool divisorGame(int n) {
    return n % 2 == 0 ? true : false;
}

int main() {
    int n = 5;

    if(divisorGame(n)) cout<<"True"<<endl;
    else cout<<"False"<<endl;

    return 0;
}