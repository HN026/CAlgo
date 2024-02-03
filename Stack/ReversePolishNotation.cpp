#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> numbers;

    for(auto token: tokens){
        if(token.size() > 1 || isdigit(token[0])){
            numbers.push(stoi(token));
        }
        else{
            int op2 = numbers.top();
            numbers.pop();
            int op1 = numbers.top();
            numbers.pop();

            switch (token[0]){
                case '+':
                    numbers.push(op1 + op2);
                    break;
                case '-':
                    numbers.push(op1 - op2);
                    break;
                case '*':
                    numbers.push(op1 * op2);
                    break;
                case '/':
                    numbers.push(op1 / op2);
                    break;
            }
        }
    }

    return numbers.top();
}

int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    
    int result = evalRPN(tokens);
    
    cout << "Result: " << result << endl;

    return 0;
}
