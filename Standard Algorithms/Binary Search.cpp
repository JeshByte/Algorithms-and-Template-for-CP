#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll isGood(ll mid,vector<ll> v1,ll n,ll w){
    ll s=0;
    for(int i=0;i<n;i++){
        if(v1[i]<mid){
            s+=mid-v1[i];
        }
        if(s>w){
            return 0;
        }
    }
    if(s<=w){
        return 1;
    }
}
void solve()
{
  ll n,w;
  cin>>n>>w;
  vector<ll>v1;
  for(int i=0;i<n;i++){
    ll input;
    cin>>input;
    v1.push_back(input);
  }  
  ll low=1,high=2*(1e9),ans=-1;
  while(low<=high){
    ll mid=low+(high-low)/2;
    ll comp=isGood(mid,v1,n,w);
    if(comp){
        ans=mid;
        low=mid+1;
    }
    else{
        high=mid-1;
    }
  }
  cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
//https://codeforces.com/problemset/problem/1873/E
