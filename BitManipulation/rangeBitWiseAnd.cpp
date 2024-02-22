#include <iostream>

using namespace std;

int rangeBitWiseAnd(int left, int right){
    int answer = 0;
    for(int bit = 30; bit>=0; bit--){
        if((left & (1<<bit)) != (right & (1<<bit))) break;
        else answer |= left & (1<<bit);
    }
    return answer;
}


int main(){
    int left = 4;
    int right = 7;

    int ans = rangeBitWiseAnd(left, right);
    cout<<ans<<endl;

    return 0;
}