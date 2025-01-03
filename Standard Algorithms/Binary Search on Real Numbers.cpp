#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
bool isGood(vector<ll>&ropes,double mid,ll n,ll k){
    ll total=0;
    for(int i=0;i<n;i++){
        total+=floor(ropes[i]/mid);
        if(total>=k){
            return true;
        }
    }
    return false;
}
void solve(ll t){
    ll n,k;
    cin>>n>>k;
    vector<ll>ropes;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        ropes.push_back(input);
    }
    double l=0,r=1e8;
    for(int i=0;i<100;i++){
        double mid=(l+r)/2;
        if(isGood(ropes,mid,n,k)){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    cout<<setprecision(20)<<l<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t=1;
  //cin>>t;
  for(int i=1;i<=t;i++){
  solve(i);
  }
  return 0;
}
//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B
