#include <bits/stdc++.h>

using namespace std;

double fractinalKnapsack(int capacity, vector<int> &weights, vector<int> &values){
    int n = weights.size();

    vector<double> ratios(n);
    for(int i = 0; i<n; i++){
        ratios[i] = (double)values[i]/weights[i];
    }
    
    vector<int> indices(n);
    for(int i = 0; i<n; i++){
        indices[i] = i;
    }

    sort(indices.begin(), indices.end(), [&](int a, int b){
        return ratios[a]>ratios[b];
    });

    double totalValue = 0.0;
    for(int i = 0; i<n; i++){
        int index = indices[i];

        if(capacity==0){
            break;
        }

        int currentWeight = min(weights[index], capacity);
        totalValue += currentWeight*ratios[index];
        capacity -= currentWeight;
    }
    return totalValue;
}

int main(){
    int capacity = 200;
    vector<int> weights = {50,40,90,120,10,200};
    vector<int> values = {40,50,25,100,30,45};

    double ans = fractinalKnapsack(capacity, weights, values);
    cout<<ans<<endl;
    return 0;
}