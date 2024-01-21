#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Define a custom comparison function for the pair
struct ComparePair {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        // Compare based on the first element of the pair (the weight)
        return p1.first > p2.first;
    }
};

int main() {
    // Example usage of priority_queue with pairs (weight, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePair> minHeap;

    // Push elements into the min heap
    minHeap.push({3, 1});
    minHeap.push({1, 2});
    minHeap.push({4, 3});
    minHeap.push({2, 4});

    // Pop elements from the min heap
    while (!minHeap.empty()) {
        pair<int, int> top = minHeap.top();
        minHeap.pop();
        cout << "Weight: " << top.first << ", Vertex: " << top.second << endl;
    }

    return 0;
}
