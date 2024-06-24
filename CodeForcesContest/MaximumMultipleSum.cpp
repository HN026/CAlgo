#include <iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t){
        int n;
        cin>>n;
        int sum = -1e9;
        int ans = 0;
        for(int i = 2; i<=n; i++){
            int tempSum = 0;
            int j = 1;
            while(i*j<=n){
                tempSum += i*j;
                j++;
            }
            if(tempSum>sum){
                ans = i;
                sum = tempSum;
            }
        }
        cout<<ans<<endl;
        t--;
    }
    return 0;
}