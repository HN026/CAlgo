#include <iostream>

using namespace std;

// This is a top Down Approach, We can solve it using Graphs and BFS as well.

int twoButtons(int steps, int n, int m){
    if(m<=n) return n-m+steps;
    int step1 = 1e9, step2 = 1e9;
    if(m%2==0) step1 = twoButtons(steps+1, n, m/2);
    else step2 = twoButtons(steps+1, n, m+1); 
    return min(step1, step2);
}

int main(){
    int n, m;
    cin>>n>>m;
    cout<<twoButtons(0, n, m)<<endl;
    return 0;
}