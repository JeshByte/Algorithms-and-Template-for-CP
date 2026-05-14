// to answer queries of kind l r x where you add x to values in indices from l to r
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
ll n;
cin>>n;
vector<ll> arr;
for(int i=0;i<n;i++){
  ll input;
  cin>>input;
  arr.push_back(input);
}
ll q;
cin>>q;
vector<ll> diff(n+2,0);
for(int i=0;i<q;i++){
  ll l,r,x; //assuming 0 based indexing
  cin>>l>>r>>x;
  diff[l]+=x;
  diff[r+1]-=x;
}
ll pre=0;
for(int i=0;i<n;i++){
  pre+=diff[i];
  cout<<arr[i]+pre<<'\n';
}
return 0;
}

