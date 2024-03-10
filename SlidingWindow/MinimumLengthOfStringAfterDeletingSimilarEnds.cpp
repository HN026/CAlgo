#include <iostream>
#include <string>

using namespace std;

int minimumLength(string s) {
    int n = s.size();

    int left = 0;
    int right = n-1;
    int ans = n;

    while(left<right){
        char l = s[left];
        char r = s[right];
        if(s[left]==s[right]){
            while(left+1<n && s[left+1] == l)
            {
                left = left+1;
            }
            while(right-1>=0 && s[right-1]==r){
                right = right-1;
            }
            left++;
            right--;
            ans = right-left+1;
        }
        else{
            return ans;
        }
    }

    if(ans<0) return 0;
    return ans;
}

int main() {
    string s = "aabccabba";
    int result = minimumLength(s);
    cout << "The minimum length of the string after deleting similar ends is: " << result << endl;
    return 0;
}