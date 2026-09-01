#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
long long tree[4 * MAXN]; // 堆式线段树数组
int sz;                   // 叶子节点的起始下标（基地址）
char op;                  // 全局操作符，方便各个函数调用

// 1. 向上更新（Push Up）：根据操作符合并左右儿子
void pushUp(int node) {
    if (op == '+') tree[node] = tree[2 * node] + tree[2 * node + 1];
    else if (op == 'u') tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    else if (op == 'd') tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

// 2. 自底向上建树（Build）
void build(int n) {
    // 寻找大于等于 n 的最小的 2 的幂
    sz = 1;
    while (sz < n) sz *= 2;
    
    // 从倒数第二层开始，一路往上合并到根节点（下标 1）
    for (int i = sz - 1; i >= 1; --i) {
        pushUp(i);
    }
}

// 3. 单点修改（Update）
// 将第 i 个位置的值加上 val，并向上更新整条链
void update(int i, long long val) {
    i += sz; // 定位到叶子节点
    tree[i] += val;
    i /= 2;  // 移到父节点
    while (i >= 1) {
        pushUp(i);
        i /= 2;
    }
}

// 4. 万能区间查询（RMQ）
// 查询区间 [L, R] 的聚合结果（支持求和、求最大、求最小）
long long rangeQuery(int L, int R) {
    L += sz; // 转换为线段树叶子节点的真实下标
    R += sz;
    
    // 初始化答案，根据操作符设置不同的“极端值”
    long long ans;
    if (op == '+') ans = 0;
    else if (op == 'u') ans = LLONG_MIN; // 求最大值，初始化为极小值
    else if (op == 'd') ans = LLONG_MAX; // 求最小值，初始化为极大值
    
    // 经典的“夹逼”游走逻辑
    while (L <= R) {
        // 如果 L 是奇数（右儿子），说明它的左兄弟不在查询范围内
        // 直接把当前节点加入答案，然后 L 跳过父节点往上爬
        if (L % 2 == 1) {
            if (op == '+') ans += tree[L];
            else if (op == 'u') ans = max(ans, tree[L]);
            else if (op == 'd') ans = min(ans, tree[L]);
            L = (L + 1) / 2;
        } else {
            L /= 2; // 如果 L 是偶数，正常往上爬
        }
        
        // 如果 R 是偶数（左儿子），说明它的右兄弟不在查询范围内
        // 直接把当前节点加入答案，然后 R 跳过父节点往上爬
        if (R % 2 == 0) {
            if (op == '+') ans += tree[R];
            else if (op == 'u') ans = max(ans, tree[R]);
            else if (op == 'd') ans = min(ans, tree[R]);
            R = (R - 1) / 2;
        } else {
            R /= 2; // 如果 R 是奇数，正常往上爬
        }
    }
    
    return ans;
}

int main() {
    int n, q;
    cin >> n >> q; // n 是数组长度，q 是操作次数
    
    // 读入初始数组（注意：这里假设数组下标从 0 开始，存在 sz 到 sz+n-1）
    for (int i = 0; i < n; ++i) {
        cin >> tree[sz + i]; // 这里为了演示简化，先读入，等 build 时再合并
    }
    
    cin >> op; // 读入操作符：'+' 求和, 'u' 求最大, 'd' 求最小
    build(n);  // 自底向上建树
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) { // 单点修改：将第 i 个位置加上 val
            int i; long long val;
            cin >> i >> val;
            update(i, val);
        } else {         // 区间查询：查询 [L, R]
            int L, R;
            cin >> L >> R;
            cout << rangeQuery(L, R) << endl;
        }
    }
    
    return 0;
}