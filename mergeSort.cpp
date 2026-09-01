#include<iostream>
using namespace std;
void merge(vector<int>& arr, int left, int mid,int right)
{
    vector<int> tmp(right-left+1);
    int i = left, j = mid + 1, k = 0;
    while (i<=mid && j<=right){
        // 细节≤展示稳定性
        if (arr[i]<=arr[j]) tmp[k++]=arr[i++];
        else tmp[k++] = arr[j++];

    }
    while (i<=mid) tmp[k++]=arr[i++];
    while (j<=right) tmp[k++]=arr[j++];
    for (int p = 0;p<k;p++) arr[left+p] = tmp[p];
}

// My Practice

void merge(vector<int>& arr, int left,int mid,int right)
{
    vector<int> tmp(right-left+1);
    int i = left,j = mid+1;k=0;
    while (i<=mid&&j<=right){
        if(arr[i]<=arr[j]) tmp[k++]=arr[i++];
        else tmp[k++]=arr[j++];
    }
    while(i<=mid)tmp[k++]=arr[i++];
    while(j<=right)tmp[k++]=arr[j++];
    for(int p = 0;p<k;p++)arr[left+p] = tmp[p];
}


void mergeSort(vector<int>& arr,int left,int right)
{
    if (left>=right) return;
    int mid = left + (right - left)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}

//My Practice

void mergeSort(vector<int>& arr,int left,int right){
    if(left>=right) return;
    int mid = left+(right-left)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}