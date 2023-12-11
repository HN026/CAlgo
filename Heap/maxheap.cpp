#include <bits/stdc++.h>

using namespace std;

class MaxHeap {
    int *arr;
    int size;
    int capacity;
    public:
    MaxHeap(int capacity){
        this->capacity = capacity;
        this->size = 0;
        this->arr = new int[capacity];
    }

    // Returns the index of the parent at the ith index.
    int parent(int i){
        if(i==0) return 0;
        return (i-1)/2;
    }

    int lchild(int i){
        return 2*i + 1;
    }

    int rchild(int i){
        return 2*i + 2;
    }

    // Heapifies a sub-tree taking the given index as the root.
    void MaxHeapify(int i){
        int l = lchild(i);
        int r = rchild(i);
        int largest = i;
        if(l < size && arr[l]>arr[i]){
            largest = l;
        }
        if(r < size && arr[r]>arr[largest]){
            largest = r;
        }
        if(largest != i){
            swap(arr[i], arr[largest]);
            MaxHeapify(largest);
        }
    }

    // Removes the root which in this 
    // case contains the maximum element. 
    int pop() {
        if(size <= 0) return INT_MIN;
        if(size == 1) {
           size--;
           return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[size-1];
        size--;

        MaxHeapify(0);
        return root;
    }

    void IncreaseKey(int i, int newVal){
        arr[i] = newVal;
        while(i!=0 && arr[parent(i)] < arr[i]){
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    int getMax()
    {
        return arr[0];
    }

    int curSize(){
        return size;
    }

    void InsertKey(int x){
        if(size==capacity){
            cout<<"Overflow: Could not Insert key"<<endl;
            return;
        }

        int i = size;
        arr[size] = x;
        size++;

        while(i!=0 && arr[parent(i)] < arr[i]){
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void DeleteKey(int i){
        IncreaseKey(i, INT_MAX);
        pop();
    }
};

int main(){
    MaxHeap h(15); 
    int k, i, n = 6, arr[10]; 
    cout << "Entered 6 keys:- 3, 10, 12, 8, 2, 14 \n"; 
    h.InsertKey(3); 
    h.InsertKey(10); 
    h.InsertKey(12); 
    h.InsertKey(8); 
    h.InsertKey(2); 
    h.InsertKey(14); 

    cout << "The current size of the heap is "
         << h.curSize() <<endl; 

    cout << "The current maximum element is " << h.getMax() 
         <<endl; 

    h.InsertKey(15); 
    h.InsertKey(5); 
    cout << "The current size of the heap is "
         << h.curSize() << "\n"; 
    cout << "The current maximum element is " << h.getMax() 
         << "\n"; 
    return 0;
}