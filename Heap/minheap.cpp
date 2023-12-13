#include <bits/stdc++.h>

using namespace std;

class MinHeap{
    int *arr;
    int size;
    int capacity;
    public: 
    MinHeap(int capacity){
        this->capacity = capacity;
        size = 0;
        arr = new int[capacity];
    }

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

    //Heapifies a sub-tree taking the given index as the root.
    void MinHeapify(int i){
        int l = lchild(i);
        int r = rchild(r);
        int smallest = i;

        if(l < size && arr[l]<arr[i]){
            smallest = l;
        }
        if(r < size && arr[r]<arr[smallest]){
            smallest = r;
        }
        if(smallest != i){
            swap(arr[i], arr[smallest]);
            MinHeapify(smallest);
        }
    }

    // Removes the root element which in this case contains the minimum element.

    int pop(){
        if(size<=0) return INT_MAX;
        if(size==1){
            size--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[size-1];
        arr[size-1] = INT_MAX;
        size--;

        MinHeapify(0);
        return root;
    }

    void DecreaseKey(int i, int newVal){
        arr[i] = newVal;

        while(i!=0 && arr[parent(i)] > arr[i]){
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    int getMin(){
        return arr[0];
    }

    int curSize(){
        return size;
    }

    void InsertKey(int x){
        if(size==capacity){
            cout<<"Overflow: Could not Insert Key"<<endl;
            return;
        }

        int i = size;
        arr[size] = x;
        size++;

        while(i!=0 && arr[i]<arr[parent(i)]){
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void DeleteKey(int i){
        DecreaseKey(i, INT_MIN);
        pop();
    }
};

int main(){
    MinHeap h(15); 
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

    cout << "The current minimum element is " << h.getMin() 
         <<endl; 

    h.InsertKey(15); 
    h.InsertKey(-5); 
    cout << "The current size of the heap is "
         << h.curSize() << "\n"; 
    cout << "The current minimum element is " << h.getMin() 
         << "\n"; 
    return 0;
}