#include <bits/stdc++.h> 
using ll=long long;
using namespace std;
void selectionSort(vector<int>& arr, int n)
{   
    for(int i=0;i<n;i++){
        ll mi=1001,ind;
        for(int j=i;j<n;j++){
            if(arr[j]<mi){
                mi=arr[j];
                ind=j;
            }
        }
        swap(arr[i],arr[ind]);
    }
}
