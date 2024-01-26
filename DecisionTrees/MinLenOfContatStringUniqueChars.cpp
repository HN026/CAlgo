#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

bool isValid(string currentString, string newString){
    unordered_set<char> charSet;

    for(auto ch: newString){
        if(charSet.count(ch)>0) return false;

        charSet.insert(ch);

        if(currentString.find(ch)!=string::npos){
            return false;
        }
    }
    return true;
}

void backtrack(vector<string> arr, string current, int index, int &maxLength){
    if(current.length()>maxLength){
        maxLength = current.length();
    }

    for(int i = index; i<arr.size(); i++){
        if(!isValid(current, arr[index])) continue;

        return backtrack(arr, current+arr[index], index+1, maxLength);
    }
}

int maxLength(vector<string> arr){
    int maxLength = 0;
    backtrack(arr, "", 0, maxLength);
    return maxLength;
}

int main(){
    vector<string> arr = {"un", "iq", "ue"};

    int ans = maxLength(arr);
    cout<<ans<<endl;

    return 0;
}