#include<iostream>

using namespace std;
// Solving that using recursion


int Partition ( int A[], int s, int e){
    int pivot= A[s];
    int cnt = 0;
    for(int i = s+1; i<=e; i++){
        if(A[i]<=pivot){
            cnt++;
        }
    }

    // Place pivot at right position

    int PivotIndex = s + cnt;
    swap(A[PivotIndex], A[s]);

    int i = s;
    int j = e;

    while( i < PivotIndex && j > PivotIndex){
        while(A[i]<=pivot){
            i++;
        }
        while(A[j]>pivot){
            j--;
        }
        
        if(i<PivotIndex && j>PivotIndex){
            swap(A[i++], A[j--]);
        }
    }

    return PivotIndex;
}


void QuickSort(int A[], int s, int e){
     if(s>=e){
        return ;
     }

     int p = Partition(A, s, e);

     QuickSort(A, s, p-1);
     QuickSort(A, p+1, e);
}





void PrintArray(int A[], int n){
    for(int i = 0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int A[] = {2,5,1,4,6,9};
    int n = sizeof(A)/sizeof(A[0]);

    QuickSort(A, 0, n-1);
    PrintArray(A, n);


    return 0;
}