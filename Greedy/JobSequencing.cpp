#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> joba, vector<int> jobb){
    return (joba[2]> jobb[2]);
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), compare);

    int maxi = jobs[0][1];
    for(int i = 0; i<n; i++){
        maxi = max(maxi,jobs[i][1]);
    }

    vector<int> slot(maxi+1, -1);
    vector<int> sequence;
    vector<int> countprofit;
    int profit = 0;
    int count = 0;
    

    for(int i = 0; i<n; i++){
        for(int j = jobs[i][1]; j>0; j--){
            if(slot[j]==-1){
                profit += jobs[i][2];
                slot[j] = jobs[i][2];
                count++;
                break;
            }
        }
    }

    for(int i = 1; i<maxi+1; i++){
        if(slot[i]!=-1){
            sequence.push_back(slot[i]);
        }
    }

    countprofit.push_back(count);
    countprofit.push_back(profit);
    return sequence;
}

int main(){
    vector<vector<int>> jobs {
        {1,1,30},
        {2,3,40},
        {3,2,10}
    };

    vector<int> ans = jobScheduling(jobs);

    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}