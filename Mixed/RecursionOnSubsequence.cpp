#include<vector>
#include<iostream>
#include<string>

using namespace std;

void subsequences(int index, vector<vector<int>> &ans, int arr[],
 vector<int> output, int n){

    if(index>=n){
        ans.push_back(output);
        return;
    }

    //include
    int element = arr[index];
    output.push_back(element);
    subsequences(index+1, ans, arr, output, n);
    output.pop_back();
    

    //exclude
    subsequences(index + 1, ans, arr, output, n);
}

int main(){
    int arr[] = {3,1,2};
    int n = 3;
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    subsequences(index, ans, arr, output,n);
    return 0;
}