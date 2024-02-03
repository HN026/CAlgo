#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>

using namespace std;

vector<int> prevSmallerElement(vector<int> &heights){
    int n = heights.size();
    stack<int> st;
    vector<int> prev(n, -1);
    for(int i = 0; i<n; i++){
        while(!st.empty() && heights[st.top()]>=heights[i]){
            st.pop();
        }
        if(!st.empty()){
            prev[i] = st.top();
        }
        st.push(i);
    }
    return prev;
}

vector<int> nextSmallerElement(vector<int> &heights){
    int n = heights.size();
    vector<int> next(n, n);
    stack<int> st;
    for(int i = n-1; i>=0; i--){
        while(!st.empty() && heights[st.top()]>=heights[i]){
            st.pop();
        }
        if(!st.empty()){
            next[i] = st.top();
        }
        st.push(i);
    }
    return next;
}

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    
    vector<int> prev(n);
    prev = prevSmallerElement(heights);

    vector<int> next(n);
    next = nextSmallerElement(heights);

    int area = INT_MIN;

    for(int i = 0; i<n; i++){
        int length = heights[i];
        int breadth = next[i] - prev[i] - 1;
        area = max(area, length * breadth);
    }

    return area;
}

int main() {
    // Example usage
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = largestRectangleArea(heights);

    cout << "Largest Rectangle Area: " << result << endl;

    return 0;
}

