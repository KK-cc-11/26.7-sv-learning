#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9; // 1e6+6 有时候不够大，容易溢出，建议用 1e9

int main(){
    int way[1001][1001];
    int d[1001];
    bool vis[1001];
    int n, m;
    cin >> n >> m;

    // 初始化邻接矩阵：自己到自己是 0，其他初始化为 inf
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            way[i][j] = (i == j) ? 0 : inf;
        }
    }

    for(int i = 0; i < m; i++){
        int a, b, k;
        cin >> a >> b >> k;
        way[a][b] = k; // 假设是有向图，如果是无向图加上 way[b][a] = k;
    }

    int s; 
    cin >> s;
    
    // 初始化距离数组和访问数组
    for(int i = 0; i < n; i++){
        vis[i] = false;
        d[i] = inf;
    }
    d[s] = 0; // ✅ 修正：起点 s 的距离设为 0

    for(int node = 0; node < n; node++){
        // 第一步：松弛操作
        for(int i = 0; i < n; i++){
            if(!vis[i] && way[s][i] != inf && d[i] > d[s] + way[s][i]){
                d[i] = d[s] + way[s][i];
            }
        }
        
        // 第二步：标记当前节点
        vis[s] = true;
        
        // 第三步：寻找下一个距离最小的未确认节点
        int minDist = inf, nextNode = -1;
        for(int i = 0; i < n; i++){
            if(!vis[i] && d[i] < minDist){
                minDist = d[i];
                nextNode = i;
            }
        }
        
        // 如果找不到下一个节点（说明剩下的点都不连通），直接退出
        if(nextNode == -1) break;
        s = nextNode;
    }

    // 输出起点 s 到所有点的最短距离
    for(int i = 0; i < n; i++){
        cout << "从 " << s << " 到 " << i << " 的最短距离是: " << d[i] << endl;
    }
    return 0;
}