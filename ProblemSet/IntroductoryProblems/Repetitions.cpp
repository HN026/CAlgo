#include <iostream>

using namespace std;

int main(){
    string s;
    cin>>s;

    int k = 1;
    int maxi = 1;
    for(int i = 1; i<s.size(); i++){
        if(s[i]==s[i-1]) k++;
        else k = 1;
        maxi = max(k, maxi);
    }
    cout<<maxi<<endl;

    return 0;
}