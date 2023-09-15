#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost){
    int n = gas.size();
    int start = 0;
    int deficit = 0;
    int balance = 0;
    for(int i = 0; i<n; i++){
        balance += gas[i] - cost[i];
        if(balance<0){
            deficit += balance;
            start = i+1;
            balance = 0;
        }
    }

    if(deficit + balance >=0){
        return start;
    }
    else{
        return -1;
    }
}

int main() {

    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout<<canCompleteCircuit(gas, cost)<<endl;
    return 0;
}