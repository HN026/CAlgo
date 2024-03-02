#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int s = 0;
        int e = n;

        while(s < e){
            int mid = s + (e-s)/2;

            if(letters[mid] <= target){
                s = mid + 1;
            }
            else{
                e = mid;
            }
        }

        return letters[s % n];
    }
};

int main() {
    Solution sol;
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'a';
    char result = sol.nextGreatestLetter(letters, target);
    cout << "The smallest letter greater than target is: " << result << endl;
    return 0;
}