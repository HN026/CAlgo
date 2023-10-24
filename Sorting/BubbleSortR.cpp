#include<iostream>

using namespace std;

void BubbleSort(int A[], int n){
    if(n == 0 || n == 1){
        return ;
    }
    for(int i = 0; i<n-1; i++){
        if(A[i]>A[i+1]){
            swap(A[i], A[i+1]);
        }
    }

    BubbleSort(A, n-1);
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
    BubbleSort(A, n);
    PrintArray(A, n);

    

    return 0;
}