#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>

using namespace std;

int maxEle(vector<int> &piles){
    int sm = 0;
    for(auto it: piles) sm = max(sm, it);
    return sm;
}

int totalHours(vector<int> &piles, int mid){
    int total = 0;
    for(int i = 0; i<piles.size(); i++){
        total += ceil(double(double(piles[i])/double(mid)));
    }
    return total;
}

int minEatingSpeed(vector<int> &piles, int h){
    int s = 0;
    int e = maxEle(piles);
    while(s<=e){
        int mid = s + (e-s)/2;
        if(totalHours(piles, mid)<=h){
            e = mid-1;
        }
        else{
            s = mid+1;
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
