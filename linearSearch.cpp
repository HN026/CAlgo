#include<iostream>

using namespace std;

int LinearSearch(int A[], int n, int size){
    for(int i = 0; i<size; i++){
        if(A[i] == n){
            return i;
        }
    }
    return -1;
}

int main()
{
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    
    cout<<"The index of 6 is: "<<LinearSearch(A,6,10)<<endl;

    return 0;

}