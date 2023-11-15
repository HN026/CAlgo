#include <iostream>
#include <vector>

using namespace std;

// Space Optimization.
int ninjaTraining(int n, vector<vector<int>> &points){
    
    vector<int> prev(4, -1);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++){
        vector<int> temp(4, -1);
        for(int last = 0; last < 4; last++){
            temp[last] = 0;
            int maxi = 0;
            for(int task = 0; task < 3; task++){
                if(task!=last){
                    int point = points[day][task] + prev[task];
                    maxi = max(maxi, point);
                }
            }
            temp[last] = maxi;
        }
        prev = temp;
    }
    return prev[3];
}


int main(){
    vector<vector<int>> points {
        {1,2,5},
        {3,1,1},
        {3,3,3}
    };

    int n = points.size();

    int ans = ninjaTraining(n, points);
    cout<<ans<<endl;
    return 0;
}