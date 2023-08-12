#include<iostream>
#include<vector>
#include<string>

using namespace std;

int sumsub(int index, int sum,
 int arr[], int n, int output){
   
   if(index==n){
    if(output==sum){
        return 1;
    }
    return 0;
   }

   // include 
   output += arr[index];
   int l = sumsub(index+1, sum, arr, n, output);
   output -= arr[index];

   //Exclude
   int r = sumsub(index+1, sum, arr, n, output);

   return l+r;
}


int main(){
    int arr[] = {1,2,1};
    int n = 3;
    int sum = 2;
    int index = 0;
    int output = 0;
    cout<<sumsub(index, sum, arr, n, output)<<endl;
    return 0;
}