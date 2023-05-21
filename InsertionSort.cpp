#include<iostream>

using namespace std;

void InsertionSort(int A[], int n){
    for(int i = 1; i<n; i++){
        int temp = A[i];
        int j = i-1;
        for(; j>=0; j--){
           if(A[j] > temp){
            A[j+1] = A[j];
           }
           else{
            break;
           }
        }
        A[j+1] = temp;
    }
}

void PrintArray(int A[], int n){
    for(int i = 0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}



int main(){
    
    int A[] = {2,1,6,4,19,0};
    int n = sizeof(A)/sizeof(A[0]);
   
    PrintArray(A, n);
    InsertionSort(A, n);
    PrintArray(A, n);
    


    return 0;
}