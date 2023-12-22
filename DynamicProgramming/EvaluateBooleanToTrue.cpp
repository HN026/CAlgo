#include <iostream>
#include <vector>

using namespace std;

int mod = 1e9+7;

int f(int i, int j, int isTrue, string &expression, vector<vector<vector<long long int>>> &dp){
    if(i>j) return 0;
    if(i==j){
        if(isTrue==1) return expression[i] == 'T';
        else return expression[i]=='F';
    }

    if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];

    long long int ways = 0;

    for(int index = i+1; index<=j-1; index+=2){
        long long int lT = f(i, index-1, 1, expression, dp);
        long long int lF = f(i, index-1, 0, expression, dp);
        long long int rT = f(index+1, j, 1, expression, dp);
        long long int rF = f(index+1, j, 0, expression, dp);

        if(expression[index]=='&'){
            if(isTrue){
                ways = (ways + (lT*rT)%mod)%mod;
            }
            else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
        }

        else if(expression[index]=='|'){
            if(isTrue){
                ways = (ways + (lT * rT) % mod + (lF * rT) % mod + (lT * rF) % mod) % mod;
            }
            else ways = (ways + (lF * rF) % mod) % mod;
        }

        else if(expression[index]=='^'){
            if(isTrue){
                ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
            }
            else ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
        }
    }

    return dp[i][j][isTrue] = ways;
}


int evaluateExp(string &expression){
    int n = expression.size();
    vector<vector<vector<long long int>>> dp(n, vector<vector<long long int>> (n, vector<long long int> (2, -1)));
    return f(0, n-1, 1, expression, dp);
}

int main(){
    string exp = "F|T^F";
    int ans = evaluateExp(exp);
    cout<<ans<<endl;
    return 0;
}