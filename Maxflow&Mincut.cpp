#include<bits/stdc++.h>
#define MAXN 101
using namespace std;

bool BFS(int ways[MAXN][MAXN],int *parent,bool *visited, 
    int n,int s, int t){
    queue<int> q;
    parent[s] = -1;
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int i = 0; i < n;i++){
            if(!visited[i]&&ways[u][i]>0){
                q.push(i);
                parent[i] = u;
                visited[i] = 1;
            }
        }
    }
    return visited[t];
}

bool DFS(int ways[MAXN][MAXN], int *parent, bool *visited, int n, int s, int t){
    if(s == t)
        return 1;
    visited[s] = 1;
    for (int i = 0; i < n;i++){
        if(ways[s][i]>0&&!visited[i]){
            parent[i] = s;
            if(DFS(ways,parent,visited,n,i,t))
                return 1;
        }
    }
    return 0;
}

int FordFulkerson(int ways[MAXN][MAXN], int n, int s, int t){
    int rGraph[MAXN][MAXN];
    // rGraph 是ways矩阵的残差网络，记录每条边当前还剩下多少容量可以走
    int parent[MAXN];
    bool visited[MAXN];

    for (int i = 0; i < n;i++)
        for (int j = 0; j < n;j++)
            rGraph[i][j] = ways[i][j];

    int max_flow = 0;

    // 这里的BFS用于搜索一条从s到t变容量大于0的路径
    // 这里对于rGraph做出了改变，其核心就是通过这个残差矩阵来操作
    while(BFS(rGraph,parent,visited,n,s,t)){
        memset(visited, false, sizeof(visited));
        int path_flow = 0xfffffff;
        for (int v = t; v != s;v = parent[v]){
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (int v = t; v != s;v = parent[v]){
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }
    return max_flow;
}