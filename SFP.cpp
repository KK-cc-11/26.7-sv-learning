# include <iostream>
# include <vector>
using namespace std;
# define MAXN 100001
vector<int> spf(MAXN+1, 1);
// caculate SPF for every number smaller than MAXN
void sieve()
{
    spf[0] = 0;
    for (int i = 2;i <= MAXN; i++){
        if (spf[i]==1){
            for(int j = i; j<= MAXN; j+=i){
                if (spf[j] == 1){
                    spf[j] = i;
                }
            }
        }
    }
}
vector<vector<int>> getFactorization(vector<int> arr){
    sieve();
    vector<vector<int>> ret;
    // arr.size() = 3
    for (int i = 0; i< arr.size(); i++){
        vector<int> Pfactors;
        // define int x to reserve every item from the input
        int x = arr[i];
        // To keep find the PF for every number at the start of the SPF of it
        while (x != 1){
            Pfactors.push_back(spf[x]);
            x = x / spf[x];
        }
        ret.push_back(Pfactors);
    }
    return ret;
}
int main(){
    vector<int> arr = {15, 17, 21};
    vector<vector<int>> pfactors = getFactorization(arr);
    // traverse a 2D array
    for (int i = 0; i< pfactors.size();i++){
        for(int j = 0;j < pfactors[i].size();j++){
            cout<<pfactors[i][j]<<" ";
            cout<<endl;
        }
    }
    cout<<endl;
    return 0;
}