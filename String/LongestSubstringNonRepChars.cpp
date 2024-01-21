#include <iostream>
#include <vector>

using namespace std;

int Longest(string s){
    int n = s.size();
    int left = 0;
    int right = 0;
    int length = 0;

    vector<int> mpp(256, -1);

    while(right < n){
        if(mpp[(int)s[right]]!=-1){
            left = max(mpp[(int)s[right]]+1, left);
        }

        mpp[(int)s[right]] = right;
        length = max(length, right-left+1);
        right++;
    }
    return length;
}

int main(){
    string s = "abcabcbb";

    int ans = Longest(s);
    cout<<ans<<endl;

    return 0;
}