#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> collision(vector<int> &nums){
    int n = nums.size();
    deque<int> dq;
    vector<int> ans;

    for(int i = 0; i<n; i++){
        if(nums[i]>0 || dq.empty()){
            dq.push_back(nums[i]);
        }
        else{
            while(true){
                int top = dq.back();
                if(abs(top)<0){
                    dq.push_back(nums[i]);
                    break;
                }
                else if(abs(top)>abs(nums[i])) break;
                else if(abs(top)==abs(nums[i])){
                    dq.pop_back();
                    break;
                }
                else{
                    dq.pop_back();
                    if(dq.empty()){
                        dq.push_back(nums[i]);
                        break;
                    }
                }
            }
        }
    }


    while(!dq.empty()){
        ans.push_back(dq.front());
        dq.pop_front();
    }

    return ans;
}




int main(){
    vector<int> nums = {5, 10, -5};

    vector<int> ans = collision(nums);
    for(auto it: ans) cout<<it<<" ";
    return 0;
}