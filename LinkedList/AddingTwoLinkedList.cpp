#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }
};

Node<int>* vectolist(std::vector<int> &ans, Node<int> *list){
    if(list == NULL){
        list = new Node<int>(ans[0]);
    }

    Node<int> *p = list;

    for(int i = 1; i < ans.size(); i++){
        Node<int> *temp = new Node<int>(ans[i]);
        temp->next = NULL;
        list->next = temp;
        list = temp;
    }

    return p;
}

void listtovec(Node<int> *first, std::vector<int> &num){
    Node<int> *temp = first;
    while(temp != NULL){
        num.push_back(temp->data);
        temp = temp->next;
    }
}

Node<int>* addTwoLists(Node<int>* first, Node<int>* second) {
    std::vector<int> num1;
    std::vector<int> num2;

    listtovec(first, num1);
    listtovec(second, num2);

    int n = num1.size();
    int m = num2.size();

    std::vector<int> ans;

    int i = n - 1;
    int j = m - 1;
    int carry = 0;

    while(i >= 0 || j >= 0){
        int sum = 0;
        if(i >= 0 && j >= 0) sum = num1[i] + num2[j] + carry;
        if(i >= 0 && j < 0) sum = num1[i] + carry;
        if(i < 0 && j >= 0) sum = num2[j] + carry;

        if(sum > 9){
            ans.push_back(sum % 10);
            carry = 1;
        } 
        else{
            carry = 0;
            ans.push_back(sum);
        }
        i--;
        j--;
    }

    if(carry){
        ans.push_back(1);
        carry = 0;
    }

    std::reverse(ans.begin(), ans.end());

    Node<int> *myanslist = NULL;

    return vectolist(ans, myanslist);
}

void deleteList(Node<int>* head) {
    while (head != NULL) {
        Node<int>* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node<int>* first = new Node<int>(9); // Represents 9 -> 4 -> 2 (249 in reverse)
    first->next = new Node<int>(4);
    first->next->next = new Node<int>(2);

    Node<int>* second = new Node<int>(5); // Represents 5 -> 6 -> 7 (765 in reverse)
    second->next = new Node<int>(6);
    second->next->next = new Node<int>(7);

    Node<int>* result = addTwoLists(first, second);


    std::vector<int> resultVector;
    listtovec(result, resultVector);

    std::cout << "Result: ";
    for (int num : resultVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


    deleteList(first);
    deleteList(second);
    deleteList(result);

    return 0;
}
