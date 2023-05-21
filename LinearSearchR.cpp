#include<iostream>

using namespace std;

int LinearSearch(int A[], int n, int key){

    static int i = 0;
    if(n==0){
       return -1;
    }
    else if(A[0]==key){
        return i;
    }
    else{
        i++;
        return LinearSearch(A+1, n-1, key);
    }
}



int main(){
    int A[] = {0,2,4,6,8,10,12,14};
    int n = sizeof(A)/sizeof(int);
    int key = 10;

    cout<<LinearSearch(A, n, key)<<endl;
    return 0;
}