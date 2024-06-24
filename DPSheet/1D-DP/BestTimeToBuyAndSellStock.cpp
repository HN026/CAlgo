#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int maxProfit = INT_MIN;
        int minI = INT_MAX;
        for(int i = 0; i<n; i++){
            if(prices[i]<minI){
                minI = prices[i];
                continue;
            }
            maxProfit = max(maxProfit, prices[i] - minI);
        }

        return maxProfit == INT_MIN ? 0 : maxProfit;
    }
};

int main(){
    Solution sol = Solution();
    vector<int> prices = {7,1,5,3,6,4};
    cout<<sol.maxProfit(prices)<<endl;
    return 0;
}