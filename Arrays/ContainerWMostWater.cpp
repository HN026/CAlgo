#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height){
    int maxArea = 0;
    int i = 0;
    int j = height.size()-1;
    while(i<j){
        int length = min(height[i], height[j]);
        int width = j-i;
        maxArea = max(maxArea, length*width);
        if(height[i]<height[j]) i++;
        else if (height[i]>height[j]) j--;
        else{
            i++;
            j--;
        }
    }
    return maxArea;
}




int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<maxArea(height)<<endl;
    return 0;
}