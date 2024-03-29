#include <iostream>
#include <vector>

using namespace std;

// Tabularization Method: 

int ninjaTraining(int n, vector<vector<int>> &points, vector<vector<int>> &dp){
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++){
        for(int last = 0; last < 4; last++){
            int maxi = dp[day-1][last]; // Initialize maxi with the current value of dp[day][last]
            for(int task = 0; task < 3; task++){
                if(task != last){
                    int point = points[day][task] + dp[day-1][task];
                    maxi = max(maxi, point);
                }
            }
            dp[day][last] = maxi;
        }
    }
    return dp[n-1][3];
}

int main(){
    vector<vector<int>> points {
        {1,2,5},
        {3,1,1},
        {3,3,3}
    };

    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(4,-1));
    int ans = ninjaTraining(n, points, dp);
    cout << ans << endl;
    
    // Print the dp table for verification
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
