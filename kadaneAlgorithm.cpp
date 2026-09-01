#include<bits\stdc++.h>
using namespace std;

// attention please
// it is particularly for a subarray which must be incessent
int kadane(int *arr,int n){
    int gmx = arr[0], cmx = arr[0];
    
    // gmx = general max, cmx = current max

    for (int i = 1; i < n;i++){
        cmx = max(arr[i], cmx + arr[i]);
        if(cmx >=gmx)
            gmx = cmx;
    }
    return gmx;
}

int main(){
    int n;
    cin >> n;
    int array[n];

    for (int i = 0; i < n;i++){
        cin >> array[i];
    }

    cout << kadane(array, n) << endl;
}