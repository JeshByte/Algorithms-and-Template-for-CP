#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define Ceil(a,b) ((a+b-1)/b)
void solve(){
  ll n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  ll i=0,j=0,wc=0,ans=1e6;
  while(j<n){
    if(s[j]=='W'){
      wc++;
    }
    if(j-i+1<k){
      j++;
      continue;
    }
    ans=min(ans,wc);
    j++;
    if(s[i]=='W'){
      wc--;
    }
    i++;
  }
  cout<<ans<<'\n';
  //https://codeforces.com/contest/1690/problem/D
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