#include<bits/stdc++.h>
#define INF 99999
using namespace std;

struct Node{
    int cost, from;
    bool was;
};

int main(){
    int n, m, c, b, k, s, ct, cur;
    cin >> n >> m;
    Node a[n];
    int arr[n][n];

    for (int i = 0; i < n;i++){
        a[i].cost = INF;
        a[i].from = 0;
        a[i].was = 0;
        for (int j = 0; j < n;j++)
            arr[i][j] = INF;
    }
    for (int i = 0; i < m;i++){
        cin >> c >> b >> k;
        arr[c][b] = k;
    }
    cin >> s;
    a[s].cost = 0;
    ct = n - 1;
    while (ct--)
    {
        int min = INF;
        for (int i = 0; i < n;i++){
            if(min>a[i].cost && !a[i].was){
                min = a[i].cost;
                cur = i;
            }
        }
        for (int i = 0; i < n;i++){
            if(a[i].cost>a[cur].cost+arr[cur][i]){
                a[i].cost = a[cur].cost + arr[cur][i];
                a[i].from = cur;
            }
        }
        a[cur].was = 1;
    }
    cout << "Cost\tSourcs Node" << endl;
    for (int i = 0; i < n;i++)
        cout << a[i].cost << "\t" << a[i].from << endl;
}