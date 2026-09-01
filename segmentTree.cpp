#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
long long arr[MAXN];
long long tree[4 * MAXN];
long long lazy[4 * MAXN];

void pushUp(int node){
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void pushDown(int node,int start,int end){
    if(lazy[node]!=0){
        int mid = (start + end) / 2;
        int leftNode = node * 2;
        int rightNode = node * 2 + 1;
        tree[leftNode] += lazy[node] * (mid - start + 1);
        tree[rightNode] += lazy[node] * (end - mid);

        lazy[leftNode] += lazy[node];
        lazy[rightNode] += lazy[node];

        lazy[node] = 0;
    }
}

void build(int node,int start,int end){
    if(start == end){
        tree[node] = arr[start];
    }
    else{
        int mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        pushUp(node);
    }
}
// very smart wit
void rangeUpdate(int node,int start,int end,int L,int R,long long v){
    if(L<=start&&end<=R){
        tree[node] += v * (end - start + 1);
        lazy[node] += v;
        return;
    }
    pushDown(node, start, end);
    int mid = (start + end) / 2;
    if(L<=mid)
        rangeUpdate(node * 2, start, mid, L, R, v);
    if(R>mid)
        rangeUpdate(node * 2 + 1, mid + 1, end, L, R, v);

    pushUp(node);
}

long long rangeQuery(int node,int start,int end,int L,int R){
    if(L<=start&&R>=end){
        return tree[node];
    }
    pushDown(node, start, end);
    int mid = start + (end - start) / 2;
    long long res = 0;
    if(L<=mid)
        res += rangeQuery(node*2, start, mid, L, R);
    if(R>mid)
        res += rangeQuery(node * 2 + 1, mid + 1, end, L, R);
    return res;
}
int main() {
    // 简单测试：假设有 4 个数字
    int n = 4;
    arr[1] = 1; arr[2] = 2; arr[3] = 3; arr[4] = 4;
    
    // 从根节点（编号为 1）开始，构建 [1, 4] 这个区间的线段树
    build(1, 1, n);
    
    cout << "根节点（整个数组的总和）: " << tree[1] << endl; // 输出 10
    return 0;
}