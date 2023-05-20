#include<iostream>


using namespace std;

int BinarySearch(int A[], int n , int size){
    int s =  0;
    int e = size - 1;
    int mid = s + (e-s)/2;

    while(s<=e){
        if(A[mid] == n){
            return mid;
        }
        else if (A[mid] > n){
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }

        mid = s + (e-s)/2;
    }

    return -1;
}


int main(){
    int A[10] = {0,1,2,3,4,5,6,7,8,9};


    cout<<"The index of 6 using Binary Search is: "<<BinarySearch(A,6,10)<<endl;


    return 0;
}