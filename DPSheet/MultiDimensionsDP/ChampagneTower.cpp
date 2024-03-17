#include <iostream>
#include <vector>

using namespace std;

double champagneTower(int poured, int query_row, int query_glass) {
    vector<double> prev;
    prev.push_back(poured);

    for(int i = 1; i<=query_row; i++){
        vector<double> curr(i+1, 0);
        for(int j = 0; j<prev.size(); j++){
            double extra = prev[j] - 1;
            if(extra>0){
                curr[j] += (double)extra/2;
                curr[j+1] += (double)extra/2;
            }
        }
        prev = curr;
    }

    if(prev[query_glass]>1) return 1;

    return prev[query_glass];
}

int main() {
    // Call the function with some test inputs
    cout << champagneTower(1, 1, 1) << endl;
    cout << champagneTower(2, 1, 1) << endl;
    cout << champagneTower(100000009, 33, 17) << endl;

    return 0;
}