#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

string frequencySort(string s);

int main() {
    string inputString;
    
    // Get input string from the user
    cout << "Enter a string: ";
    cin >> inputString;

    // Call the frequencySort function
    string sortedString = frequencySort(inputString);

    // Display the sorted string
    cout << "Sorted String: " << sortedString << endl;

    return 0;
}

string frequencySort(string s) {
    unordered_map<char, int> mp;
    int n = s.size();
    for(int i = 0; i < n; i++){
        mp[s[i]] += 1;
    }

    auto comp = [&](char a, char b){
        if(mp[a] == mp[b]){
            return a > b;
        }
        else{
            return mp[a] > mp[b];
        }
    };

    sort(s.begin(), s.end(), comp);
    return s;
}