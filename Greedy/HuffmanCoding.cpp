#include <iostream>
#include <vector>
#include <queue>

#define MAX_TREE_HT 100

using namespace std;

class HuffmanNode{
    public:
    char data;
    int frequency;
    HuffmanNode *left;
    HuffmanNode *right;

    HuffmanNode(char data, int frequency){
        this->data = data;
        this->frequency = frequency;
        this->left = left;
        this->right = right;
    }
};

class MinHeap {
    public:
    int size;
    int capacity;
    vector<HuffmanNode*> heap;

    MinHeap(int capacity){
        this->size = 0;
        this->capacity = capacity;
        heap.resize(capacity);
    }

    void swapMinHeapNode(HuffmanNode**a, HuffmanNode **b){
        HuffmanNode *temp = *a;
        *a = *b;
        *b = temp;
    }

    void minHeapify(int index){
        int smallest = index;
        int left = 2*index+1;
        int right = 2*index+2;

        if(left < size && heap[left]->frequency<heap[smallest]->frequency){
            smallest = left;
        }
        if(right < size && heap[right]->frequency<heap[smallest]->frequency){
            smallest = right;
        }
        if(smallest!=index){
            swapMinHeapNode(&heap[smallest], &heap[index]);
            minHeapify(smallest);
        }
    }

    int isSizeOne(){
        return (size==1);
    }

    HuffmanNode *extractMin(){
        HuffmanNode *temp = heap[0];
        heap[0] = heap[size-1];

        size--;
        minHeapify(0);
        return temp;
    }

    void InsertMinHeap(HuffmanNode *node){
        int i = size;
        heap[size] = node;
        size++;
        while(i != 0 && node->frequency<heap[(i-1)/2]->frequency){
            swapMinHeapNode(&heap[i], &heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void buildMinHeap(){
        int n = size - 1;
        for(int i = (n-1)/2; i>=0; --i){
            minHeapify(i);
        }
    }
};

class HuffmanCoding {
    public:
    MinHeap *minHeap;

    HuffmanCoding(int capacity){
        minHeap = new MinHeap(capacity);
    }

    HuffmanNode* newNode(char data, int freq){
        return new HuffmanNode(data, freq);
    }

    void buildHuffmanTree(char data[], int freq[], int size){
        HuffmanNode *left, *right, *top;

        for(int i = 0; i<size; i++){
            minHeap->heap[i] = newNode(data[i], freq[i]);
        }

        minHeap->size = size;
        minHeap->buildMinHeap();

        while(!minHeap->isSizeOne()){
            left = minHeap->extractMin();
            right = minHeap->extractMin();

            top = newNode('$', left->frequency+right->frequency);

            top->left = left;
            top->right = right;
            
            minHeap->InsertMinHeap(top);
        }
    }

    void printCodes(HuffmanNode *root, int arr[], int top){
        if(root->left){
            arr[top] = 0;
            printCodes(root->left, arr, top+1);
        }
        if(root->right){
            arr[top] = 1;
            printCodes(root->right, arr, top+1);
        }
        if(!root->left && !root->right){
            cout<<root->data<<": ";
            printArr(arr, top);
        }
    }

    void HuffmanCodes(char data[], int freq[], int size){
        buildHuffmanTree(data, freq, size);

        int arr[MAX_TREE_HT];
        int top = 0;

        printCodes(minHeap->heap[0], arr, top);
    }

    void printArr(int arr[], int n){
        for(int i = 0; i<n; i++){
            cout<<arr[i];
        }
        cout<<endl;
    }

    ~HuffmanCoding(){
        delete minHeap;
    }
};

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCoding huffmanCoder(size);
    huffmanCoder.HuffmanCodes(arr, freq, size);

    return 0;
}