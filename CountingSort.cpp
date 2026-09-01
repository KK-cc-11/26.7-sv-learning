#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void CountingSort(vector<int>& arr){
    if (arr.empty()) return;
    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(),arr.end());
    int range = max_val - min_val + 1;
    vector<int> count(range,0);
    for(int x : arr){
        count[x-min_val]++;
    }
    int index = 0;
    for (int i = 0; i<range;i++){
        while (count[i]-- > 0){
            arr[index++] = i+minval;
        }
    }
}

// My Practice
void coutingSort(vector<int>& arr){
    if (arr.empty()) return;
    // 1.Define the max_val and min_val
    
    int max_val = max_element(arr.begin(),arr.end());
    int min_val = min_element(arr.begin(),arr.end());

    // 2.Create the count array to dot down the times of each element
    int range = max_val-min_val+1;
    vector<int> count(range,0);
    for(int x : arr){
        count[x-min_val]++;
    }
    int idx = 0;
    for (int i = 0;i<range;i++){
        while (count[i]-->0){
            arr[idx++]=i+min_val;
        }
    }
}