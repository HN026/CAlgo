#include<iostream>

using namespace std;

int main() {
    int a[] = {1,2,3,4,5,6,7};
    int n = 7;
    int i = 0;
    int k = 2; // We are going to shift the array by 2 digits to the right

    for(int i = 0; i<k; i++){
        int temp = a[n-1];
        for(int j = n-1; j>0; j--){
            a[j] = a[j-1];
        }
        a[0] = temp;
    }

    for(int i = 0; i<n ;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}