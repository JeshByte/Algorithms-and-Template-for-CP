void merge(vector<int>& arr,int s,int e){
    int mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    vector<int> first(len1),second(len2);
    int k=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[k++];
    }
    int i=0,j=0;
    k=s;
    int res=0;
    while(i<len1 && j<len2){
        if(first[i]<=second[j]){
            arr[k++]=first[i++];
        }
        else{
            arr[k++]=second[j++];
            res+=len1-i;
        }
    }
    while(i<len1){
        arr[k++]=first[i++];
    }
    while(j<len2){
        arr[k++]=second[j++];
    }
}
void sort(vector<int>& arr,int s,int e){
    int res=0;
    if(s>=e){
        return res;
    }
    int mid=s+(e-s)/2;
    res+=sort(arr,s,mid);
    res+=sort(arr,mid+1,e);
    res+=merge(arr,s,e);
}
void mergeSort(vector < int > & arr, int n) {
    sort(arr,0,n-1);
}
