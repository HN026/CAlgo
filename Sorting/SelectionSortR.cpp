#include<iostream>
#include<limits>

using namespace std;


void SelectionSort(int A[], int n){
    if(n==0 || n==1){
        return ;
    }
    int min = 0;
    for(int i = 0; i<n; i++){
        if(A[i]<A[0]){
            min = i;
        }
    }
    swap(A[0], A[min]);
    SelectionSort(A+1, n-1);
}


void PrintArray(int A[], int n){
    for(int i = 0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}




int main(){
    int A[] = {5,4,3,2,1};
    int n = sizeof(A)/sizeof(A[0]);
    SelectionSort(A, n);
    PrintArray(A,n);
    return 0;
}