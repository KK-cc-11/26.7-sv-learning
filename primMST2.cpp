#include<bits/stdc++.h>
#include<climits>
using namespace std;

int main(){
    int x, y, z, i, j;
    int v, e;// v = vertices e = edges
    cin >> v >> e;
    int g[v][v];// used 2Dim array to save the graph
    fill(&g[0][0], &g[0][0] + v * v, INT_MAX);// an advanced version in order to avoid input some rubbish data
    for (i = 0; i < e;i++){
        cin >> x >> y >> z;
        g[x][y] = g[y][x] = z;// no direction with weight(z)
    }
    int parent[v]; // every vertex's parent 
    int key[v]; // minimum
    bool used[v];// ~visited
    for (i = 0; i < v;i++)
        key[i] = INT_MAX, used[i] = false;

    // u = origin
    int u = 0;
    used[u] = true;
    parent[u] = -1;

    for (j = 0; j < v - 1;j++){
        // new key
        for (i = 0; i < v;i++){
            if(g[u][i]&&!used[i]&&g[u][i]<key[i]){
                key[i] = g[u][i], parent[i] = u;
            }
        }
        // among unused vertices to find the smallest key vertix
        int min = INT_MAX, minI;
        for (i = 0; i < v;i++){
            if(!used[i] && key[i]<min)
                min = key[i], minI = i;
        }
        // reset minI as the new 'u'
        u = minI;
        used[u] = 1;
    }
    cout << "Edge Weight\n";
    for (int i = 1; i < v;i++){
        cout << parent[i] << "-" << i << " " << g[i][parent[i]] << endl;
    }
}