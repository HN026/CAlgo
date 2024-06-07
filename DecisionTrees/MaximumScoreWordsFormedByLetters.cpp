#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    int maxScore;
    int n;
  public:
    bool isPossible(string word, unordered_map<char, int> wordCount, unordered_map<char, int> &letterCount) {
        for (auto ch : word) {
            wordCount[ch]++;
            if (wordCount[ch] > letterCount[ch])
                return false;
        }
        return true;
    }

    void dfs(int index, vector<string> &words, vector<int> &score, unordered_map<char, int> &letterCount, unordered_map<char, int> &wordCount) {
        if (index == n) {
            int sum = 0;
            for (auto it : wordCount)
                sum += it.second * score[it.first - 'a'];
            maxScore = max(maxScore, sum);
            return;
        }
        // Include
        if (isPossible(words[index], wordCount, letterCount)) {
            for (auto ch : words[index])
                wordCount[ch]++;
            dfs(index + 1, words, score, letterCount, wordCount);
            for (auto ch : words[index])
                wordCount[ch]--;
        }
        // Exclude
        dfs(index + 1, words, score, letterCount, wordCount);
    }

    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score) {
        maxScore = 0;
        n = words.size();
        unordered_map<char, int> letterCount, wordCount;
        for (auto ch : letters)
            letterCount[ch]++;
        dfs(0, words, score, letterCount, wordCount);
        return maxScore;
    }
};

int main() {
    Solution sol = Solution();
    vector<string> words = {"dog", "cat", "dad", "good"};
    vector<char> letters = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
    vector<int> score = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cout << sol.maxScoreWords(words, letters, score) << endl;
    return 0;
}