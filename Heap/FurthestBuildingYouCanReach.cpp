#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findFurthestBuilding(vector<int> &heights, int bricks, int ladders){
    int n = heights.size();
    priority_queue<int> pq;

    for(int i = 0; i<n; i++){
        int diff = heights[i+1] - heights[i];
        if(diff<=0) continue;

        bricks -= diff;
        pq.push(diff);

        if(bricks<0){
            if(ladders==0) return i;

            ladders -= 1;
            bricks += pq.top();
            pq.pop();
        }
    }

    return n-1;
}

int main(){
    vector<int> heights = {4,2,7,6,9,14,12};
    int bricks = 5;
    int ladders = 1;

    int ans = findFurthestBuilding(heights, bricks, ladders);
    cout<<ans<<endl;
    
    return 0;
}