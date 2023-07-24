#include <iostream>
#include <vector>

using namespace std;


bool isPossible(vector<int> &a, int n, int m, int mid){
    int StudentCount = 1;
    int PageSum = 0;
    for(int i = 0; i<n; i++){
        if(PageSum + a[i] <= mid){
           PageSum += a[i];
        }
        else{
            StudentCount++;
            if(StudentCount>m || a[i]>mid){
                return false;
            }
            PageSum = 0;
            PageSum += a[i];
        }
    }
    return true;
}



int BookAllocation(vector<int> &a, int n, int m)
{
    int s = 0;
    int Sum = 0;
    for (int i = 0; i < n; i++)
    {
        Sum += a[i];
    }
    int e = Sum;
    int ans = -1;
    int mid = s + (e-s)/2;

    if(m>n){
        return -1;
    }


    while(s<=e){
       if(isPossible(a, n, m, mid)){
        ans = mid;
        e = mid - 1;
       }
       else{
        s = mid + 1;
       }
       mid = s + (e-s)/2;
    }
    return ans;
}

int main()
{
    int n = 4;
    int m = 2;
    vector<int> a = {12,34,67,90};

    cout<<BookAllocation(a,n,m);

    return 0;
}