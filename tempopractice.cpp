#include<bits.h>
#define MAXN 25;
using namespace std;
int find(int x,int *parent){
    if(parent[x]==x){
        return x;
    }
    return parent[x] = find(parent[x],parent);
}
bool detectCycle(int ar[][2],int *parent,int *rootRank,int m){
    for(int i = 0;i<m;i++){
        int x = find(ar[i][0],parent);
        int y = find(ar[i][1],parent);
        if(x==y) return true;
        if(rootRank[x]>rootRank[y]) parent[y]=x,rootRank[x]+=rootRank[y];
        else parent[x] = y, rootRank[y]+=rootRank[x];
    }
}
int main(){
    int ar[MAXN][2];
    int parent[MAXN];
    int rootRank[MAXN];
    int n,m;
    cin>>n>>m;
    for(i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        ar[i][0] = a,ar[i][1] = b;
    }
    for(int i = 0;i<n;i++) parent[i] = i, rootRank[i] = 1
}