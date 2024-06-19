#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> q;
        int n = deck.size();
        for(int i = 0; i<n; i++) q.push(i);
        
        vector<int> result(n);
        for(int i =0; i<n; i++){
            result[q.front()] = deck[i];
            q.pop();
            
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return result;
    }
};

int main(){
    Solution sol = Solution();
    vector<int> deck = {17,13,11,2,3,5,7};
    vector<int> res = sol.deckRevealedIncreasing(deck);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}