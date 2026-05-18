#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
ll modExpo(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
 
        exp = exp >> 1;
 
        base = (base * base) % mod;
    }
    return result;
}
ll findInverse(ll n,ll MOD){
    return modExpo(n,MOD-2,MOD);
}
ll divideModulo(ll a, ll b, ll m) {
    ll b_inv = findInverse(b, m);
    return ((a % m) * b_inv) % m;
}
void printWithPrecision(auto n){
    cout << fixed << setprecision(6) << n << '\n';
}
void solve(ll t,ll testcases){
    ll n;
    cin>>n;
    vector<ll> arr;
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
        mp[input]++;
    }
    ll ans=0;
    ans+=mp[0];
    if(min(mp[1],mp[2])>=1){
        ll use=min(mp[1],mp[2]);
        ans+=use;
        mp[1]-=use;
        mp[2]-=use;
    }
    if(mp[1]>=1){
        ans+=(mp[1]/3);
    }
    if(mp[2]>=1){
        ans+=(mp[2]/3);
    }
    cout<<ans<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  cin>>t;
  for(int i=1;i<=t;i++){
  solve(i,t);
  }
  return 0;
}
// for interactive
// cout<<" "<<endl;
// fflush(stdout);
