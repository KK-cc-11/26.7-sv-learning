#include<iostream>
#include<vector>
#include<queue>
#include<deque>
using namespace std;

vector <int> v[10];
int dist[10];
bool vis[10];

// 1.Help you to define the level of each node

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    vis[s] = true;// visited
    while(q.size()){
        int p = q.front();
        q.pop();
        for(int i = 0; i<v[p].size();i++){
            if(!vis[v[p][i]]){
                dist[v[p][i]]=dist[p]+1;
                q.push(v[p][i]);
                vis[v[p][i]]=true;
            }
        }
    }

}
// 2.0-1BFS
// 使用双端队列 deque
deque<int> dq; 
dq.push_front(s); // 起点放入队头
dist[s] = 0;
vis[s] = true;

while(!dq.empty()){
    int p = dq.front();
    dq.pop_front();
    
    // 遍历 p 的所有邻居 (假设边权存在 weight 数组或结构体中)
    for(auto &edge : v[p]){ 
        int neighbor = edge.to;
        int w = edge.weight; // 权值只能是 0 或 1
        
        if(!vis[neighbor]){
            vis[neighbor] = true;
            dist[neighbor] = dist[p] + w;
            
            // 核心区别：根据权值决定插入队头还是队尾
            if(w == 0){
                dq.push_front(neighbor); // 权值为0，放队头
            } else {
                dq.push_back(neighbor);  // 权值为1，放队尾
            }
        }
    }
}

// about 01BFS 
deque<int> dq;
dq.push_front(s);
dist[s] = 0;
vis[s] = true;

while(!dp.empty()){
    int p = dp.front();
    dp.pop_front();
    // edge is a structure with the elements respectively called to and weight
    for(auto &edge : v[p]){
        int neighbor = edge.to;
        int w = edge.weight;
        if(!vis[neighbor]){
            vis[neighbor] = true;
            dist[neighbor] = dist[p] + w;
        }
        if(w==0){
            dp.push_front(neighbor);
        }
        else dp.push_back(neighbor);
    }
}