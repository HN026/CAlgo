#include<iostream>

using namespace std;

int main(){
    int a[] = {1,2,3,0,0,5,2,9,0,2,3};
    int n = sizeof(a)/sizeof(int);

    int j = 0;
    for(int i = 0; i<n; i++){
        if(a[i]!=0){
            a[j] = a[i];
            j++;
        }
    }
    for(;j<n; j++){
        a[j] = 0;
    }

    for(int i = 0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}