#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return (a[2]>b[2]);
}

int main(){
    
    vector<vector<int>> test {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    sort(test.begin(), test.end(), compare);

    for(auto i : test){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }


    return 0;
}