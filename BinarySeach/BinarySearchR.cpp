#include<iostream>

using namespace std;

void PrintArray(int A[], int s, int e){
    for(int i = s; i<e; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int BinarySearch(int A[], int s, int e, int key){
    int mid = s + (e-s)/2;
    PrintArray(A,s,e);

    if(s>e){
        return -1;
    }
    else if (A[mid]==key){
        return mid;
    }
    else if(A[mid]>key){
        return BinarySearch(A, s, mid-1, key);
    }    
    else{
        return BinarySearch(A, mid+1, e, key);
    }
}

int main(){
    int A[] = {2,4,6,8,10,12,14};
    int n = sizeof(A)/sizeof(int);
    int key = 10;

    cout<<BinarySearch(A,0,n-1,key)<<endl;
    



    return 0;
}