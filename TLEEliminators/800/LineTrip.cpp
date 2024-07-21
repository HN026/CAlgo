#include <iostream>
#include <vector>

using namespace std;

bool isPossible(int mid, vector<int> a, int x){
    int currentFuel = mid;
    int lastStation = x;
    int n = a.size();
    
    for(int i = 0; i<n; i++){
        if(a[i] - lastStation > currentFuel) return false;
        currentFuel = mid;
        lastStation = a[i];
    }
    
    if(x - lastStation > currentFuel) return false;
    currentFuel = mid - (x - lastStation);
    lastStation = x;
    
    for(int i = n-1; i>=0; i--){
        if(lastStation-a[i]> currentFuel) return false;
        currentFuel = mid;
        lastStation = a[i];
    }
    
    if(lastStation > currentFuel) return false;
    return true;
}

int lineTrip(int n, int x, vector<int> &a){
    int s = 0;
    int e = 2*x;
    int ans = 2*x;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(isPossible(mid, a, x)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;
        vector<int> a(n);
        for(int i = 0; i<n; i++) cin>>a[i];
        int ans = lineTrip(n, x, a);
        cout<<ans<<endl;
    }

    return 0;
}