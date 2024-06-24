#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int left = 0, cnt = 0, maxSum = 0, windowSum = 0, zeroSum = 0;
        int n = customers.size();
        for(int right = 0; right < n; right++){
            zeroSum += grumpy[right]==0 ? customers[right] : 0;
            windowSum += grumpy[right]==1 ? customers[right] : 0;
            cnt++;
            while(cnt > minutes ){
                if(grumpy[left]==1) windowSum -= customers[left++];
                cnt--;
            }
            maxSum = max(maxSum, windowSum);
        }
        return maxSum + zeroSum;
    }
};

int main(){
    Solution sol = Solution();
    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy = {0,1,0,1,0,1,0,1};
    int minutes = 3;
    cout << sol.maxSatisfied(customers, grumpy, minutes) << endl;
    return 0;
}