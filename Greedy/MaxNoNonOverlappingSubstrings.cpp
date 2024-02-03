#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int checkValid(string s, int i, vector<int> left, vector<int> right){
    int idx = s[i] - 'a';

    int r = right[idx];

    for(int j = i; j<r; j++){
        int index = s[j] - 'a';
        if(left[index]<i) return -1;
        r = max(r, right[index]);
    }

    return r;
}


vector<string> maxNumOfSubstrings(string s){
    int n = s.size();
    vector<string> result;
    vector<int> left(26, -1);
    vector<int> right(26, -1);

    for(int i = 0; i<n; i++){
        int idx = s[i] - 'a';
        if(left[idx]==-1){
            left[idx] = i;
        }
        right[idx] = i;
    }

    int r_most = -1;

    for(int i = 0; i<n; i++){
        int idx = s[i] - 'a';
        if(i==left[idx]){
            
            // Function to check if the substring contains all the occurences of each character or not.
            int new_r = checkValid(s, i, left, right);

            if(new_r != -1){
                string sub = s.substr(i, new_r - i + 1);

                if(new_r<r_most){
                    result.back() = sub;
                }
                else{
                    result.push_back(sub);
                }

                r_most = new_r;
            }

        }
    }

    return result;
}

int main(){

    string input = "abab";
    vector<string> result = maxNumOfSubstrings(input);

    for(auto it: result){
        cout<<it<<endl;
    }

    return 0;
}