#include <iostream>
using namespace std;

string longestPalindrome(string s) {
    string res = "";
    int n = s.size();
    int maxi = 0;
    for(int i = 0; i<n; i++){
        int left = i;
        int right = i;

        // Odd length Palindromes:
        while(left>=0 && right<n && s[left]==s[right]){
            if(right-left+1>maxi){
                maxi = right-left+1;
                res = s.substr(left, maxi);
            }
            left -= 1;
            right += 1;
        }

        // Even Length Palindromes:
        left = i;
        right = i+1;
        while(left>=0 && right<n && s[left]==s[right]){
            if(right-left+1>maxi){
                maxi = right-left+1;
                res = s.substr(left, maxi);
            }
            left -= 1;
            right += 1;
        }
    }
    return res;
}

int main() {
    string input;
    
    // Input the string
    cout << "Enter a string: ";
    cin >> input;

    // Call the function
    string result = longestPalindrome(input);

    // Output the result
    cout << "Longest Palindrome: " << result << endl;

    return 0;
}
