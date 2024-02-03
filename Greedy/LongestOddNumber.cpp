#include <iostream>

using namespace std;

string largestOddNumber(string num) {
    int n = num.size();
    for (int i = n - 1; i >= 0; i--) {
        if (num[i] - '0' & 1) {
            return num.substr(0, i + 1);
        }
    }
    return "";
}


int main() {
    // Test the largestOddNumber function
    string num1 = "12345";
    string result1 = largestOddNumber(num1);
    cout << "The largest odd number for " << num1 << " is: " << result1 << endl;

    string num2 = "246801";
    string result2 = largestOddNumber(num2);
    cout << "The largest odd number for " << num2 << " is: " << result2 << endl;

    return 0;
}

