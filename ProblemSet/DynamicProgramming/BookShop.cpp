#include <iostream>
#include <vector>

using namespace std;

int f(int index, int money, vector<int> &price, vector<int> &pages, vector<vector<int>> &dp){
    if(money==0) return 0;
    if(index==0){
        if(money>=price[index]) return pages[index];
        else return 0;
    }

    if(dp[index][money] != -1) return dp[index][money];

    int notTake = f(index-1, money, price, pages, dp);
    int take = 0;
    if(money-price[index]>=0) take = pages[index] + f(index-1, money-price[index], price, pages, dp);

    return dp[index][money] = max(notTake, take);
}


int maxPages(vector<int> &price, vector<int> &pages, int money){
    int n = price.size();
    vector<vector<int>> dp(n, vector<int> (money+1, -1));
    return f(n-1, money, price, pages, dp);
}


int main(){
    vector<int> price = {4,8,5,3};
    vector<int> pages = {5,12,8,1};
    int money = 10;
    int n = price.size();

    int ans = maxPages(price, pages, money);
    cout<<ans<<endl;

    return 0;
}