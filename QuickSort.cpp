#include<iostream>
using namespace std;

void quickSort(int arr[],int left,int right){
    int i = left,j = right;
    int tmp;
    int pivot = arr[(left+right)/2];
    while(i<=j){
        while(arr[i]<pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<=j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    if(left<j)quickSort(arr,left,j);
    if(i<right)quickSort(arr,i,right);
}


// My Practice
void quick(int arr[],int left,int right){
    if(left>=right) return;
    int i = left; 
    int j = right;
    int pivot = (arr[left]+arr[right])/2;
    while(i<=j){
        while(arr[i]<pivot) i++;
        while(pivot<arr[j]) j--;
        if(i<=j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    if(left<j) quick(arr,left,j);
    if(i<right) quick(arr,i,right);
}

void printArray(int arr[],int size){
    int i;
    for(i=0;i<size;i++)printf("%d",arr[i]);
    printf("\n");
}
//Smarter Way To Deal With the Problem
#include <iostream>
#include <vector>
using namespace std;

// 划分函数
int partition(vector<int>& arr, int left, int right) {
    int mid = left + (right - left) / 2;
    int pivot = arr[mid];

    // 将 pivot 换到最右边，方便后续处理
    swap(arr[mid], arr[right]);

    int i = left; // i 指向“下一个小于 pivot 的元素应该放的位置”
    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    // 将 pivot 放回它最终应该在的位置
    swap(arr[i], arr[right]);
    return i;
}
// My Practice
int partition(vector<int>& arr, int left,int right)
{
    int mid = left + (right - left)/2;
    int pivot = arr[mid];
    swap(arr[mid],arr[right]);
    int i = left;
    for(int j =0;j<right;j++){
        if(arr[j]<=pivot) swap(arr[i++],arr[j]);
    }
    swap(arr[i],arr[right]);
    return i;
}


// 快速排序主函数
void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return; // 递归终止条件

    int pivotIndex = partition(arr, left, right); // 划分
    quickSort(arr, left, pivotIndex - 1);         // 递归左半部分
    quickSort(arr, pivotIndex + 1, right);        // 递归右半部分
}

// My Practice
void quickSort(vector<int>& arr,int left,int right)
{
    if (left>=right) return;
    int pivotIdx = partition(arr,left,right);
    quickSort(arr,left,pivotIdx-1);
    quickSort(arr,pivotIdx+1,right);
}

int main() {
    vector<int> arr = {3, 1, 4, 2};
    quickSort(arr, 0, arr.size() - 1);

    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}