#include<bits/stdc++.h>
#define INF 9999999
using namespace std;
int main(){
    // initialize the graph
    int n,m;
    cin>>n>>m;
    int arr[n][n];
    // fill(&arr[0][0], &arr[0][0] + n * n, INF);
    
    // a better way to initialize to avoid the [i][i] situation
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j)
                arr[i][j] = 0;              // 自己到自己的距离，设为 0
            else
                arr[i][j] = INF; // 其他点之间，设为无穷大
    }
}
    // input the weight

    for(int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[b][a] = arr[a][b] = c;
    }

    // traverse every vertix as 'u', 'u' is not origin but the transection
    // use dp to do this sorts of things
    for(int u = 0; u<n;u++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i!=j){
                    if(arr[i][j]>arr[i][u]+arr[u][j])
                        arr[i][j] = arr[i][u] + arr[u][j];
                }
            }
        }
    }
    int st,fin;// start and finish
    cin>>st>>fin;
    cout<<arr[st][fin]<<endl;
}
