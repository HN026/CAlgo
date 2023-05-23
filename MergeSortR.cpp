#include<iostream>

using namespace std;


void Merge(int *A, int s, int e){
   int mid = s+(e-s)/2;

   int l1 = mid - s + 1;
   int l2 = e-mid;

   int *first = new int[l1];
   int *second = new int[l2];

   int k = s;
   for(int i = 0; i<l1; i++){
    first[i] = A[k++];
   }

   int g = mid + 1;
   for(int i = 0; i<l2; i++){
    second[i] = A[g++];
   }

    int index1 = 0;
    int index2 = 0;
    int m = s;

    while(index1 < l1 && index2 < l2){
        if(first[index1] < second[index2]){
            A[m++] = first[index1++];
        }
        else{
            A[m++] = second[index2++];
        }
    }
    
    while(index1<l1){
        A[m++] = first[index1++];
    }

    while(index2<l2){
        A[m++] = second[index2++];
    }
}


void MergeSort(int *A, int s, int e){
    if(s>=e){
        return;
    }

    int mid = s + (e-s)/2;

    MergeSort(A,s,mid);
    MergeSort(A,mid+1,e);

    Merge(A,s,e);
}

void PrintArray(int A[], int n){
    for(int i = 0;  i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}


int main(){
    
    int arr[] = {5,2,4,1,3,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    

    MergeSort(arr,0,n-1);
    PrintArray(arr,n);

    return 0;
}