#include<iostream>
using namespace std;
int powModBasic(int x,int n, int M){
    long res = 1;
    for(int i = 1;i<=n;i++){
        res = (res*x)%M;
    }
    return res;
}
long powModAdanced(int x,int n,int M){
    long res = 1;
    while(n>=1){
        if(n&1){
            res = (res*x)%M;
            n--;
        }
        else{
            x=(x*x)%M;
            n/=2;
        }
    }
    return res;
}