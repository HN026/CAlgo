#include <iostream>
#include <queue>

// Insertion (push operation): O(log N)
// When you insert an element into the max heap, it will take O(log N) time, where N is the number of elements in the heap.

// Access the maximum element (top operation): O(1)
// Getting the maximum element (the top element) from a max heap is an O(1) operation since the maximum element is always at the top of the heap.

// Removal of the maximum element (pop operation): O(log N)
// Removing the maximum element from a max heap also takes O(log N) time, as it involves reorganizing the heap to maintain the max-heap property.

using namespace std;

int main(){
    
    priority_queue<int, vector<int>, less<int>> maxHeap;

    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);
    maxHeap.push(50);
    maxHeap.push(40);

    while(!maxHeap.empty()){
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    return 0;
}