#include <iostream>
#include <string>

using namespace std;

long long compute_hash(string s){
    const int p = 31;
    const int m = 1e9+9;
    long long hash_value = 0;
    long long p_pow = 1;

    for(char c: s){
        hash_value = (hash_value + (c-'a'+1)*p_pow)%m;
        p_pow = (p_pow*p)%m;
    }

    return hash_value;
}

int main(){

    string input_string;
    cout<<"Enter a string:"<<endl;
    cin>>input_string;


    long long hash_result = compute_hash(input_string);

    cout<<"Hash of the string "<<input_string<<" is: "<<hash_result<<endl;

    return 0;
}