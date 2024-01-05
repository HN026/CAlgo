#include <iostream>
#include <vector>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> l(n, 1);
    vector<int> r(n, 1);

    for(int i = 1; i<n; i++) if(ratings[i]>ratings[i-1]) l[i] = l[i-1] + 1;
    for(int i = n-2; i>=0; i--) if(ratings[i]>ratings[i+1]) r[i] = r[i+1] + 1;

    int sum = 0;
    for(int i = 0; i<n; i++) sum += max(l[i], r[i]);

    return sum;
}

int main() {
    vector<int> ratings = {1,0,2};
    int totalCandies = candy(ratings);
    cout << "Total number of candies needed: " << totalCandies << endl;
    return 0;
}