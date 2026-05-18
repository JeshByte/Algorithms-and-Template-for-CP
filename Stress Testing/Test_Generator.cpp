#include<bits/stdc++.h>

using namespace std;
using ll=long long;

ll randomNumberBetwee(ll a, ll b){
    if(a>b)
        swap(a,b);
    return a + rand()%(b - a + 1);
}
int main(int argc, char* argv[]){
    srand(atoi(argv[1]));
    ll t=1;
    cout<<t<<endl;
    for(int j=0;j<t;j++){
        ll a = randomNumberBetwee(0,1e17);
        ll n=2;
        cout<<a<<" "<<n<<endl;
        for(int i=0;i<n;i++){
            ll ele=randomNumberBetwee(0,9);
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    
}
