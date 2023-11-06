// *******Recursion*********

// #include <iostream>
// #include <vector>

// using namespace std; 

// // Time Complexity: O(N) & // Space Complexity: O(N)

// int fibonacci(int n, vector<int> &dp){
//     if(n<=1) return n;
//     if(dp[n]!=-1) return dp[n];
//     return dp[n] = fibonacci(n-1, dp) + fibonacci(n-2,dp);
// }

// int main(){
//     int n;
//     cout<<"Enter the term you want: ";
//     cin>>n;
//     vector<int> dp(n+1, -1);
//     cout<<fibonacci(n,dp)<<endl;
//     return 0;
// }

// *******Tabulation*********

// Better than Recursion because we won't be using the stack space.

// #include <iostream>
// #include <vector>

// using namespace std;

// int main(){
//     int n;
//     cout<<"Enter the term number: "<<endl;
//     cin>>n;
//     vector<int> dp(n+1, -1);
//     dp[0] = 0;
//     dp[1] = 1;

//     for(int i = 2; i<=n; i++){
//         dp[i] = dp[i-1] + dp[i-2];
//     }

//     cout<<dp[n]<<endl;
    
//     return 0;
// }

// *****Space optimized******

#include <iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter the term you want: "<<endl;
    cin>>n;
    int prev = 1;
    int prev2 = 0;
    for(int i = 2; i<=n; i++){
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    cout<<prev<<endl;
    return 0;
}