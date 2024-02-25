#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> primeFactors(int n){
    vector<pair<int,int>> ans;
    for(int i = 2; i*i<=n; i++){
        if(n%i==0){
            int count = 0;
            while(n%i==0){
                count++;
                n = n/i;
            }
            ans.push_back({i, count});
        }
    }
    if(n>1) ans.push_back({n, 1});
    return ans;
}

int main(){
    int n = 15;
    
    auto ans = primeFactors(n);

    for(auto p : ans) {
        cout << p.first << " appears " << p.second << " time(s)" << endl;
    }

    return 0;
}