#include<iostream>
#include<vector>

using namespace std;

int findPivot(const vector<int> &arr ){
    int s = 0;
    int e = arr.size() - 1;

    while(s< e) {
        int mid = s + (e-s)/2;

        if (arr[mid] > arr[e]){
            s = mid + 1;
        }
        else {
            e = mid;
        }
    }
    return s;
}


int main() {
    vector<int> sorted_rotated_array = {4,5,6,7,0,1,2};
    int pivot = findPivot(sorted_rotated_array);
    cout<<"Pivot is at index: "<<pivot<<endl;
    return 0;
}
