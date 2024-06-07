#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> splitStringToVector(string &str) {
    vector<string> result;
    istringstream stream(str);
    string word;

    while (stream >> word)
        result.push_back(word);
    return result;
}

int main() {
    string input = "This is an example string to be split into words";
    vector<string> words = splitStringToVector(input);
    for (const auto &word : words) {
        cout << word << endl;
    }
    return 0;
}