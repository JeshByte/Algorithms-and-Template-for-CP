#include <bits/stdc++.h> 
using namespace std;
void bubbleSort(vector<int>& arr, int n)
{ for(int i=1;i<n;i++){
        int flag=0;
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j+1],arr[j]);
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
}
void print(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
}

