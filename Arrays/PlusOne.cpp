#include <iostream>
#include <vector>

using namespace std;

vector<int> PlusOne(vector<int> &v){
    int i = v.size()-1;
    int carry = 1;
    while(i>=0){
        int sum = v[i] + carry;
        if(sum>9){
            carry = 1; 
            v[i--] = 0;
        }
        else{
            carry = 0;
            v[i--] = sum;
        }
    }
    if(carry) v.insert(v.begin(), 1);
    return v;
}

int main(){
    vector<int> v = {9,9,9};
    vector<int> ans = PlusOne(v);
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}