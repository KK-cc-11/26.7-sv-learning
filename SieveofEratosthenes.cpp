# include <iostream> // 输出输出头文件
#include <vector>
using namespace std;
vector<int> sieve(int n){
    vector<bool> prime(n+1,1);
    for (int p = 2; p*p<=n;p++){
        if (prime[p] == 1){
            for(int i = p*p;i<=n;i+=p){
                prime[i]=0;
            }

        }
    } 
    vector<int> res;
    for (int p = 2;p<=n;p++){
        if(prime[p]){
            res.push_back(p);
        }
    }   
    return res;
}
int main() {
    int n = 35;
    vector<int> res = sieve(n);
    for(auto ele : res){
        cout << ele <<' ';
    }
    return 0;
}