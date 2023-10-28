#include <iostream>
#include <queue>

//Time complexity: Insertion O(logn)
//Min-element: O(1)
// Deletion: O(logn)

// int: Tells us about the data type of the elements in the heap 
// which is integer in this case.
// vector<int> : This specifies the underlying container that the priority queue uses. In this case, it's a vector of integers.
// greater<int> : This is the comparison function used to determine the order of elements in the heap. std::greater<int> specifies that elements will be ordered in such a way that the greatest element (maximum) is at the top, effectively making it a min heap.


using namespace std;

int main(){
    
    
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(5);
    minHeap.push(2);
    minHeap.push(8);
    minHeap.push(1);

    while(!minHeap.empty()){
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    return 0;
}