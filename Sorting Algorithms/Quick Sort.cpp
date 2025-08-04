#include <bits/stdc++.h>
int partition(vector<int>&arr,int s,int e){
    int pivot=arr[s];
    int co=0;
    for(int i=s;i<=e;i++){
        if(arr[i]<pivot){
            co++;
        }
    }
    int ind=s+co;
    swap(arr[s],arr[ind]);
    int i=s,j=e;
    while(i<ind && j>ind){
        if(arr[i]<pivot){
            i++;
            continue;
        }
        if(arr[j]>=pivot){
            j--;
            continue;
        }
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    return ind;
}
void sort(vector<int>&arr,int s,int e){
    if(s>=e){
        return;
    }
    int ind=partition(arr,s,e);
    sort(arr,s,ind-1);
    sort(arr,ind+1,e);
}
vector<int> quickSort(vector<int> arr)
{
    sort(arr,0,arr.size()-1);
    return arr;
}
