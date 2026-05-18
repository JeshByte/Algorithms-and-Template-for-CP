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
    ll n,x1,x2,k;
    cin>>n>>x1>>x2>>k;
    if(n<=3){
        cout<<1<<'\n';
        return;
    }
    ll ans=1e9;
    ll dest1=(x2+1)%n;
    ll dest2=(x2-1+n)%n;
    if(dest1==0){
        dest1=n;
    }
    if(dest2==0){
        dest2=n;
    }
    //cout<<dest1<<" "<<dest2<<'\n';
    if(x1<=dest1){
        ans=min(ans,dest1-x1);
        ans=min(x1+n-dest1,ans);
    }
    else{
        ans=min(ans,x1-dest1);
        ans=min(ans,n-x1+dest1);
    }
    if(x1<=dest2){
        ans=min(ans,dest2-x1);
        ans=min(x1+n-dest2,ans);
    }
    else{
        ans=min(ans,x1-dest2);
        ans=min(ans,n-x1+dest2);
    }
    //cout<<ans<<'\n';
    ans+=(k+1);
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
