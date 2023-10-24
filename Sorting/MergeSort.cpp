#include<iostream>

using namespace std;

void MergeSort(int A[], int B[], int C[], int m, int n){

    int l = 0;
    int f = 0;
    int c = 0;
    
    while(l < m && f < n){
        if(A[l]>B[f]){
            C[c] = B[f];
            c++;
            f++;
        }
        else if (A[l]<B[f]){
            C[c] = A[l];
            c++;
            l++;
        }
        else {
            C[c] = A[l];
            c++;
            l++;
            f++;
        }
    }

    while(l < m){
        C[c] = A[l];
        c++;
        l++;
    }

    while(f < n){
        C[c] = B[f];
        c++;
        f++;
    }
}

void DisplayArray(int A[], int n){
    for(int i = 0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int A[5] = {3,7,12,45,133};
    int n1 = sizeof(A)/sizeof(int);
    int B[5] = {1,5,6,23,54};
    int n2 = sizeof(B)/sizeof(int);
    int C[10];
    MergeSort(A,B,C,n1,n2);
    DisplayArray(C, n1+n2);

    return 0;
}