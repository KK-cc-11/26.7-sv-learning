#include <iostream>
#include <vector>
using namespace std;
 vector<bool> prime(10001,1);
vector<int> sieve(int n){
    for (int p = 2;p*p<=n;p++){
        if(prime[p]){
            for (int i=p*p;i<=n;i+=p){
                prime[i]=0;
            }
        }
    }
    vector<int> res;
    for (int p = 2;p<=n;p++){
        if (prime[p]){
            res.push_back(p);
        }
    }
    return res;
}
int main(){
    int n,k;cin>>n>>k;
    vector<int>primes = sieve(n);
    int times = 0;
    for (int i = 0; i<primes.size()-1;i++){
        int candidate = primes[i]+primes[i+1]+1;
        if (candidate<=n&&prime[candidate]){
            times++;
        }
    }
    cout<<(times>=k?"YES" : "NO")<<endl;
    return 0;
}