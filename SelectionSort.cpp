#include <iostream>
#include<limits>

using namespace std;

void SelectionSort(int A[], int n)
{
    for(int i = 0; i<n-1; i++){
        
        int min = A[i];
        for(int j = i; j<n; j++){
            if(A[j]<min){
                min = A[j];
            }
        }
        for(int j = i; j<n; j++){
            if(A[j] == min) {
                swap(A[i], A[j]);
                break;
            }
        }
    }
}

void PrintArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{

    int arr[] = {1,2,3,4,5};

    int size = sizeof(arr) / sizeof(arr[0]);

    PrintArray(arr, size);
    SelectionSort(arr, size);
    PrintArray(arr, size);

    return 0;
}