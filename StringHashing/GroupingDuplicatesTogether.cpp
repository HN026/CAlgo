#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long compute_hash(string s){
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;

    for(char c: s){
        hash_value = (hash_value + (c-'a'+1)*p_pow)%m;
        p_pow = (p_pow * p)%m;
    }

    return hash_value;
}

vector<vector<int>> group_identical_strings(vector<string>s){
    int n = s.size();
    vector<pair<long long, int>> hashes(n);

    for(int i = 0; i<n; i++){
        hashes[i] = {compute_hash(s[i]), i};
    } 

    sort(hashes.begin(), hashes.end());

    vector<vector<int>> groups;
    vector<int> currGroup;

    for(int i = 0; i<n; i++){
        if(i>0 && hashes[i].first != hashes[i-1].first){
            groups.push_back(currGroup);
            currGroup.clear();
        }
        currGroup.push_back(hashes[i].second);
    }

    if(!currGroup.empty()){
        groups.push_back(currGroup);
    }

    return groups;
}


int main(){
    vector<string> strings = {"abc", "bcd", "abc", "def", "bcd", "xyz"};

    vector<vector<int>> hashResult = group_identical_strings(strings);

    cout<<"Optimised Approach"<<endl;
    for(auto group: hashResult){
        if(group.size()>1){
            cout<<"Dup Group: ";;
            for(auto idx: group){
                cout<<strings[idx]<<" ";
            }
            cout<<endl;
        }
    }


    return 0;
}