#include <iostream>
#include <vector>

using namespace std;

void Intersection(vector<int> &v1, vector<int> &v2){
    int n = v1.size();
    int m = v2.size();

    int i = 0;
    int j = 0;
    vector<int> ans;
    while(i<n && j<m){
        if(v1[i]==v2[j]){
            ans.push_back(v1[i]);
            i++;
            j++;
        }
        else if(v1[i]<v2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v1 = {1,2,3,4,4,5,5,9};
    vector<int> v2 = {2,2,3,3,5};

    Intersection(v1,v2);
    return 0;
}