#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
    int K;
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > K) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > K) {
            pq.pop();
        }
        return pq.top();
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    int k = 3;
    KthLargest* obj = new KthLargest(k, nums);

    vector<int> valuesToAdd = {3, 5, 10, 9, 4};
    for (int val : valuesToAdd) {
        int kthLargest = obj->add(val);
        cout << "After adding " << val << ", the " << k << "th largest element is " << kthLargest << endl;
    }

    delete obj;
    return 0;
}