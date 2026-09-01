#include <iostream>
#include <vector>
using namespace std;

void dfsRec(vector<vector<int>> &adj,
vector<bool> &vis, int s, vector<int> &res)
{
    vis[s] = true;
    res.push_back(s);
    for(int i : adj[s]){
        if (!vis[i]) dfsRec(adj,vis,i,res);
    }
}

vector<int> dfs(vector<vector<int>> &adj)
{
    vector<bool> vis(adj.size(),0);
    vector<int> res;
    dfsRec(adj,vis,0,res);
    return res;
}

void addEdge(vector<vector<int>> & adj,int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

