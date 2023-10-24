#include <iostream>

using namespace std;

void BubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
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

    int arr[] = {5, 4, 3, 2, 1};

    int size = sizeof(arr) / sizeof(arr[0]);

    PrintArray(arr, size);
    BubbleSort(arr, size);
    PrintArray(arr, size);

    return 0;
}