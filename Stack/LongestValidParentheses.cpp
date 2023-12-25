// Stack approach

#include <iostream>
#include <stack>

using namespace std;

int longestValidParentheses(string s) {
        int answer = 0;
        stack<int> stack;
        stack.push(-1);

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    answer = max(answer, i - stack.top());
                }
            }
        }

        return answer;
}

int main() {
    string input = "(())";
    int result = longestValidParentheses(input);
    cout << "Longest valid parentheses: " << result << endl;

    return 0;
}
