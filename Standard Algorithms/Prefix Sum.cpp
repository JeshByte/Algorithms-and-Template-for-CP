#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(ll t){
    ll n;
    cin>>n;
    vector<ll>v1,pre(n+1);
    for(int i=0;i<n;i++){
        ll inp;
        cin>>inp;
        v1.push_back(inp);
    }
    pre[0]=0;
    for(int i=1;i<n+1;i++){
        pre[i]=v1[i-1]+pre[i-1];
    }
    ll ans=-1;
    for(int i=1;i<n;i++){
        ans=max(ans,__gcd(pre[i],pre[n]-pre[i]));
    }
    cout<<ans<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  cin>>t;
  for(int i=1;i<=t;i++){
  solve(i);
  }
  return 0;
}
//https://codeforces.com/problemset/problem/1780/B
