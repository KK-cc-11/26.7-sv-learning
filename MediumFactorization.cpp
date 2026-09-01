# include <iostream>
# include <vector>
using namespace std;
# define MAXN 100001
vector<int> spf(MAXN+1,1);
void sieve(){
    for(int i = 2; i<=MAXN;i++){
        if (spf[i]==1){
            for(int j = i;j<=MAXN;j+=i){
                if (spf[j]==1){
                    spf[j] = i;
                }
            }
        }
    }
}
vector<vector<int>> getFactorization(vector<int> arr){
    sieve();
    vector<vector<int>> res;
    for (int i = 0;i<arr.size();i++){
        int x = arr[i];
        vector<int> pfactor;
        while (x!=1){
            pfactor.push_back(spf[x]);
            x /= spf[x];
        }
        res.push_back(pfactor);
    }
    return res;
}
int main(){
    vector<int> arr = {8,17,21};
    vector<vector<int>> pfactors = getFactorization(arr);
    for(int i = 0;i<pfactors.size();i++){
        cout<<1;
        for(int j = 0;j<pfactors[i].size();j++){
            cout<<"X"<<pfactors[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}