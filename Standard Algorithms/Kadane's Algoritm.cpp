#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Ceil(a,b) ((a+b-1)/b)
ll checkParity(ll n){
    return n&1;
}
ll maxSubarraySum(vector<ll> &arr) {
    ll res = arr[0];
    ll maxEnding = arr[0];
 
    for (int i = 1; i < arr.size(); i++) {
 
        maxEnding = max(maxEnding + arr[i], arr[i]);
      
 
        res = max(res, maxEnding);
    }
    return res;
}
void solve(){
   ll n;
   cin>>n;
   vector<ll>arr;
   for(int i=0;i<n;i++){
    ll input;
    cin>>input;
    arr.push_back(input);
   }
   vector<vector<ll>>req_arr;
   vector<ll>temp;
   for(int i=0;i<n-1;i++){
    temp.push_back(arr[i]);
    if(checkParity(arr[i])!=checkParity(arr[i+1])){
        continue;
    }
    else{
        req_arr.push_back(temp);
        temp.clear();
    }
   }
   temp.push_back(arr[n-1]);
   req_arr.push_back(temp);
   ll ans=(1e9)*(-1);
   for(int i=0;i<req_arr.size();i++){
    ll temp_ans=maxSubarraySum(req_arr[i]);
    ans=max(ans,temp_ans);
   }
   cout<<ans<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
//https://codeforces.com/problemset/problem/1899/C