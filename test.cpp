
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int parent[MAXN], rootRank[MAXN];

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (rootRank[x] < rootRank[y]) swap(x, y);
    parent[y] = x;
    rootRank[x] += rootRank[y];
    return true;
}

int main() {
    int n = 5, m = 4;
    for (int i = 0; i < n; i++) parent[i] = i, rootRank[i] = 1;

    int edges[][2] = {{0,1},{2,3},{1,3},{0,4}};
    for (auto& e : edges) {
        if (!unite(e[0], e[1])) {
            cout << "Cycle detected: (" << e[0] << "," << e[1] << ")\n";
        }
    }
    cout << "No cycle found\n";
    return 0;
}