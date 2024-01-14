#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>

using namespace std;

int maxEle(vector<int> &piles){
    int maxi = INT_MIN;
    for(auto it: piles) maxi = max(maxi, it);
    return maxi;
}

int totalhours(vector<int> &piles, int rate){
    int totalh = 0;
    for(int i = 0; i<piles.size(); i++){
        totalh += ceil((double)piles[i]/(double)rate);
    }
    return totalh;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int s = 0;
    int end = maxEle(piles);
    while(s<=end){
        int mid = s + (end-s)/2;
        if(totalhours(piles, mid)<=h){
            end = mid - 1; 
        }
        else{
            s = mid + 1;
        }
    }

    return s;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    int result = minEatingSpeed(piles, h);
    cout << "Minimum eating speed required: " << result << endl;
    return 0;
}
