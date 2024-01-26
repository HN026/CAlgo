#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

/* Using floyd Warshall Algorithm */

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> matrix(n, vector<int>(n, 1e9));
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        matrix[u][v] = wt;
        matrix[v][u] = wt;
    }
    for (int i = 0; i < n; i++)
        matrix[i][i] = 0;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    int overmin = INT_MAX;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] <= distanceThreshold) {
                k++;
            }
        }
        if (k <= overmin) {
            overmin = k;
            ans = i;
        }
    }
    return ans;
}

int main() {
    int n = 6;
    vector<vector<int>> edges = {{0, 1, 10}, {0, 2, 1}, {2, 3, 1}, {1, 3, 10}, {1, 4, 5}, {3, 4, 1}, {4, 5, 1}};
    int distanceThreshold = 20;

    int result = findTheCity(n, edges, distanceThreshold);

    cout << "The city with the smallest number of cities within distance " << distanceThreshold << " is: " << result << endl;

    return 0;
}
