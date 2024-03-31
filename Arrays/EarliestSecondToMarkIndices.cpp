#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> arr;
    vector<int> ci;
    int n;
public:

    bool isValid(int till){
        vector<int> pos(n+1, -1);

        for(int j = 0; j<=till; j++) pos[ci[j]] = j;

        for(int i = 1; i<=n; i++) if(pos[i]==-1) return false;

        vector<pair<int,int>> pos_and_ind;
        for(int j = 1; j<=n; j++){
            pos_and_ind.push_back({pos[j], j});
        }

        sort(pos_and_ind.begin(), pos_and_ind.end());

        int used_till = 0;
        for(auto [pos, ind]: pos_and_ind){
            int req = 1 + arr[ind-1];
            if(used_till + req > pos+1) return false;
            used_till += req;
        }
        return true;
    }


    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        n = nums.size();
        arr = nums;
        ci = changeIndices;

        int s = 0;
        int e = ci.size() - 1;
        int ans = -1;
        while(s<=e){
            int t = s + (e-s)/2;
            if(isValid(t)){
                ans = t+1;
                e = t-1;
            }
            else{
                s = t+1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> changeIndices = {4, 3, 2, 1, 0};
    cout << sol.earliestSecondToMarkIndices(nums, changeIndices) << endl;
    return 0;
}