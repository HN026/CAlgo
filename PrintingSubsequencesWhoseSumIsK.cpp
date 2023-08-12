#include<iostream>
#include<vector>
#include<string>

using namespace std;

void sumsub(int index, vector<int> &ans, int sum,
 int arr[], int n, int output){
   
   if(index==n){
    if(output==sum){
        for(auto it: ans) cout<<it<<" ";
        cout<<endl;
    }
    return;
   }

   // include 
   ans.push_back(arr[index]);
   output += arr[index];
   sumsub(index+1, ans, sum, arr, n, output);
   output -= arr[index];
   ans.pop_back();

   //Exclude
   sumsub(index+1, ans, sum, arr, n, output);
}


int main(){
    int arr[] = {1,2,1};
    int n = 3;
    int sum = 2;
    int index = 0;
    vector<int> ans;
    int output = 0;
    sumsub(index, ans, sum, arr, n, output);
    return 0;
}