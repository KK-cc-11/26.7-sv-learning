// be attention to the 01knapsack vs completed knapsack

// in this way, it should be careful to shift the equation of dp[i][j]

// because every coin can be utilized for unlimited times

#include<bits/stdc++.h>
#define INF 1e9
using namespace std;
int main(){
    int n;
    int v = 1;
    cin >> n;
    int coins[n];
    for (int i = 0; i < n;i++){
        cin >> coins[i];
    }
    int amount;
    cin >> amount;
    int dp[n + 1][amount + 1];
    for (int i = 0; i <= n;i++){
        for (int j = 0; j <= amount;j++){
            if (j == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = INF;
        }
    }
    for (int i = 1; i <= n;i++){
        int c = coins[i - 1];
        for (int j = 1; j <= amount;j++){
            if (j >= c){
                dp[i][j] = min(dp[i - 1][j], dp[i][j - c] + v);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    if(dp[n][amount]==INF)
        cout << "-1";
    else
        cout << "最少的硬币数是：" << dp[n][amount];
}