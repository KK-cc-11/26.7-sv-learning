#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, W;
    cin >> n >> W;
    int items[n+1][2];
    for (int i = 1; i <= n;i++){
        cin >> items[i][0] >> items[i][1];
    }

    int dp[W + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n;i++){
        int v, w;// value and weight
        v = items[i][0];
        w = items[i][1];
        for (int j = 0; j <= W; j++)
        {
            if(j>=w){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
}

/*
The essense of dp is acctually how to come up with the transition 
equation toward the dp matrics especially for the 2D dp case
And actually for some of the other forms of the dp is exactly utilizing other effective
data structure to make that equaltion work in a more efficient 
way
*/