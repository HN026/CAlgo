#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int k = 0;
    int l;
    int z;
    int maxi = 0;
    for(int i = 0; i<n; i++){
        cin>>z;
        if(i==0) l = z;
        else if(i!=0 && maxi>z) k += maxi-z;
        l = z;
        maxi = max(z, maxi);
    }
    cout<<k<<endl;
    return 0;
}