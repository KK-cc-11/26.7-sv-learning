#include <iostream>
#include <vector>
using namespace std;

void dfsRec(vector<vector<int>> &adj,vector<bool> &vis,int s,vector<int> &res){
    vis[s] = 1;
    res.push_back(s);
    for(int i : adj[s]){
        if(!vis[i]) dfsRec(adj,vis,i,res);
    }
}

vector<int> dfs(vector<vector<int>> &adj){
    vector<bool> vis(adj.size(),false);
    vector<int> res;
    // every node should be covered
    for(int i = 0;i<adj.size();++i){
        if(!vis[i]){
            dfsRec(adj,vis,i,res);
        }
    }
    return res;
}
