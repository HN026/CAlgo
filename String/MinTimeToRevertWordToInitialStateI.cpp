#include <iostream>
#include <string>

using namespace std;

bool isEqual(string word, string temp){
    int n = word.size();
    for(int i = 0; i<n; i++){
        if(temp[i]!='*' && word[i]!=temp[i]){
            return false;
        }
    }
    return true;
}

int minimumTime(string word, int k){
    string temp = word;
    int count = 0;

    do{
        temp =  temp.substr(k) + string(k, '*');
        count++;
    } while(!isEqual(word, temp));

    return count;
}

int main(){

    string word = "abaaba";
    // abaaba
    // aba***
    int k = 3;

    int ans = minimumTime(word, k);
    cout<<ans<<endl;

    return 0;
}