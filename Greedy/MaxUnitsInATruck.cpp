#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        vector<int> maxUnits(n);
        for(int i = 0; i<n; i++){
            maxUnits[i] = boxTypes[i][1];
        }
        vector<int> indices(n);
        for(int i = 0; i<n; i++) indices[i] = i;

        sort(indices.begin(), indices.end(), [&](int a, int b){
            return maxUnits[a]>maxUnits[b];
        });

        int maxans = 0;
        for(int i = 0; i<n; i++){
            int index = indices[i];
            
            if(truckSize==0) break;

            int cursize = min(boxTypes[index][0], truckSize);
            maxans += cursize * boxTypes[index][1];
            truckSize -= cursize;
        }

        return maxans;
}

int main(){
    vector<vector<int>> boxTypes = {{1,3}, {2,2}, {3,1}};
    int truckSize = 4;

    int ans = maximumUnits(boxTypes, truckSize);
    cout<<ans<<endl;
    return 0;
}