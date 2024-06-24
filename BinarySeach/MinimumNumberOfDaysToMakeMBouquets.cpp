#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isOkay(int mid, vector<int> &bloomDay, int m, int k){
        int n = bloomDay.size();

        int countCons = 0, goodb = 0;
        for(int i = 0; i<n; i++){
            if(bloomDay[i]<=mid) countCons++;
            else countCons = 0;

            if(countCons==k){
                goodb++;
                countCons = 0;
            }
        }
        return goodb >=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long)m * (long)k > n) return -1;

        int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = r;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(isOkay(mid, bloomDay, m, k)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3, k = 1;
    cout<<s.minDays(bloomDay, m, k);
    return 0;
}