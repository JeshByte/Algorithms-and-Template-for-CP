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
ll numGenerator(ll d,ll t){
    ll ans=0;
    for(int i=0;i<t;i++){
        ans=ans*10+d;
    }
    return ans;
}
void solve(ll t,ll testcases){
    ll a,n;
    cin>>a>>n;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        ll input;
        cin>>input;
        arr.push_back(input);
    }
    // if(a==0){
    //     cout<<min(abs(arr[0]-a),abs(arr[1]-a))<<'\n';
    //     return;
    // }
    vector<ll> jl,jg;
    vector<ll> digits;
    ll tp=a;
    while(tp){
        digits.push_back(tp%10);
        tp=tp/10;
    }
    if(digits.empty()){
        digits.push_back(0);
    }
    reverse(digits.begin(),digits.end());
    ll len=digits.size();
    for(int i=0;i<len;i++){
        if(digits[i]==arr[0]){
            jl.push_back(arr[0]);
            continue;
        }
        if(digits[i]==arr[1]){
            jl.push_back(arr[1]);
            continue;
        }
        if(digits[i]<arr[0]){
            ll ind=jl.size()-1;
            bool found=false;
            ll limit=0;
            if(arr[0]==0){
                limit=1;
            }
            for(int j=ind;j>=limit;j--){
                if(jl[j]==arr[1]){
                    jl[j]=arr[0];
                    found=true;
                    break;
                }
            }
            if(found){
                ll req=len-i;
                for(int j=0;j<req;j++){
                    jl.push_back(arr[1]);
                }
            }
            else{
                jl.clear();
                ll req=len-1;
                for(int j=0;j<req;j++){
                    jl.push_back(arr[1]);
                }
            }
            break;
        }
        else if(digits[i]>arr[0] && digits[i]<arr[1]){
            jl.push_back(arr[0]);
            ll req=len-i-1;
            for(int j=0;j<req;j++){
                jl.push_back(arr[1]);
            }
            break;
        }
        else if(digits[i]>arr[1]){
            ll req=len-i;
            for(int j=0;j<req;j++){
                jl.push_back(arr[1]);
            }
            break;
        }
    }
    for(int i=0;i<len;i++){
        if(digits[i]==arr[0]){
            jg.push_back(arr[0]);
            continue;
        }
        if(digits[i]==arr[1]){
            jg.push_back(arr[1]);
            continue;
        }
        if(digits[i]>arr[1]){
            ll ind=jg.size()-1;
            bool found=false;
            for(int j=ind;j>=0;j--){
                if(jg[j]==arr[0]){
                    jg[j]=arr[1];
                    found=true;
                    break;
                }
            }
            if(found){
                ll req=len-i;
                for(int j=0;j<req;j++){
                    jg.push_back(arr[0]);
                }
            }
            else{
                jg.clear();
                ll req=len+1;
                if(arr[0]==0){
                    jg.push_back(arr[1]);
                    req--;
                }
                for(int j=0;j<req;j++){
                    jg.push_back(arr[0]);
                }
            }
            break;
        }
        else if(digits[i]<arr[0]){
            ll req=len-i;
            for(int j=0;j<req;j++){
                jg.push_back(arr[0]);
            }
            break;
        }
        else if(digits[i]>arr[0] && digits[i]<arr[1]){
            jg.push_back(arr[1]);
            ll req=len-i-1;
            for(int j=0;j<req;j++){
                jg.push_back(arr[0]);
            }
            break;
        }
    }
    ll ans=1e17;
    ll val=0;
    for(int i=0;i<jl.size();i++){
        val=val*10+jl[i];
    }
    //cout<<val<<'\n';
    if(!jl.empty()){
    ans=min(ans,abs(a-val));
    }
    val=0;
    for(int i=0;i<jg.size();i++){
        val=val*10+jg[i];
    }
    if(a<=9){
        ll res=min(abs(arr[0]-a),abs(arr[1]-a));
        res=min(abs(val-a),res);
        cout<<res<<'\n';
        return;
    }
    //cout<<val<<'\n';
    if(!jg.empty()){
        ans=min(ans,abs(a-val));
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
