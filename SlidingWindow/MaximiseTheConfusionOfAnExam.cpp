#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int f(char a, string &answerKey, int k){
        int left = 0, ans = INT_MIN, n = answerKey.size(), cnt = 0;
        for(int right = 0; right<n; right++){
            if(answerKey[right]==a) cnt++;
            while(cnt > k){
                if(answerKey[left]==a) cnt--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int a = f('T', answerKey, k);
        int b = f('F', answerKey, k);
        return max(a, b);
    }
};

int main(){
    Solution s;
    cout << s.maxConsecutiveAnswers("TTFF", 2) << endl;
    return 0;
}