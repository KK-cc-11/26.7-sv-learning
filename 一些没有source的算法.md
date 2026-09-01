# Rabin-Karp 算法
-
>本质是用了一个滚动哈希其实就是slide window

用上一个窗口的哈希值，直接 O(1) 推导出下一个窗口的哈希值！
公式大概是：新哈希 = (旧哈希 - 最高位*权重) * 进制 + 新进来的最低。

# Hash

``` c++
// 假设我们要在 text 中找 pattern
string text = "abcdefg";
string pattern = "cde";

int n = text.length();
int m = pattern.length();
int base = 31; // 进制
long long mod = 1e9 + 7; // 取模，防止数字溢出

// 1. 计算目标 pattern 的哈希值
long long target_hash = 0;
long long power = 1; // 记录 base^(m-1)，用于踢掉最高位
for (int i = 0; i < m; ++i) {
    target_hash = (target_hash * base + (pattern[i] - 'a' + 1)) % mod;
    if (i < m - 1) power = (power * base) % mod;
}

// 2. 在 text 上滑动窗口
long long window_hash = 0;
for (int i = 0; i < n; ++i) {
    // 加上新进来的字符
    window_hash = (window_hash * base + (text[i] - 'a' + 1)) % mod;

    // 如果窗口还没满，继续往后走
    if (i < m - 1) continue; 

    // 如果窗口满了，检查哈希值是否匹配
    if (window_hash == target_hash) {
        // 防止哈希冲突，这里再做一次真实的字符串比对
        if (text.substr(i - m + 1, m) == pattern) {
            cout << "Found at index: " << i - m + 1 << endl;
        }
    }

    // 3. 核心魔法：踢掉最高位的字符，为下一次滑动做准备
    // 减去最高位字符 * base^(m-1)
    window_hash = (window_hash - (text[i - m + 1] - 'a' + 1) * power % mod + mod) % mod;
}

```