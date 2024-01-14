#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string shortestPalindrome(string s){
    string t = s;
    reverse(t.begin(), t.end());

    const string_view string_s(s);
    const string_view string_t(t);

    int n = s.size();

    for(int i = 0; i<n; i++){
        if(string_s.substr(0, n-i) == string_t.substr(i)){
            return t.substr(0, i) + s;
        }
    }

    return t + s;
}

int main(){
    string s = "aacecaaa";  // Try abb to understand one complex case.
    
    string a = shortestPalindrome(s);
    cout<<a<<endl;

    return 0;
}