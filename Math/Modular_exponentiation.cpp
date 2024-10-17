#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
long long modExpo(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
 
        exp = exp >> 1;
 
        base = (base * base) % mod;
    }
    return result;
}
void solve(ll t){
    vector<int>n,k;
    for(int i=0;i<t;i++){
        ll input;
        cin>>input;
        n.push_back(input);
    }
    for(int i=0;i<t;i++){
        ll input;
        cin>>input;
        k.push_back(input);
    }
    ll con=(1e9)+7;
    for(int i=0;i<t;i++){
        ll ans=modExpo(2,k[i],1e9 + 7);
        cout<<ans<<'\n';
    }
    //https://codeforces.com/contest/2025/problem/B
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin>>t;
  solve(t);
  return 0;
}