#include <bits/stdc++.h>

using namespace std;

string AddBinary(string a, string b){
    string result = "";
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    while(i>=0 || j>=0){
        int sum = carry;
        if(i>=0) sum += a[i--] - '0';
        if(j>=0) sum += b[j--] - '0';
        carry = sum > 1 ? 1 : 0;
        result += to_string(sum % 2);
    }
    if(carry) result += '1';
    reverse(result.begin(), result.end());
    return result;
}


int main(){
    string a = "11";
    string b = "1";
    cout<<AddBinary(a, b)<<endl;
    return 0;
}