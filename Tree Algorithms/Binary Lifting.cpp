void build(vector<vector<ll>>& child,vector<ll>& parent,ll n,vector<vector<ll>>& dp,ll LOG,vector<ll>& depth){
    stack<ll> st;
    st.push(1);
    dp[1][0]=1;
    while(!st.empty()){
        ll v=st.top();
        st.pop();
        dp[v][0]=parent[v];
        depth[v]=depth[parent[v]]+1;
        for(int i=1;i<=LOG;i++){
            dp[v][i]=dp[dp[v][i-1]][i-1];
        }
        for(auto it:child[v]){
            st.push(it);
        }
    }
}
ll query(ll x,ll k,vector<vector<ll>>& dp,vector<ll>& depth,ll LOG){
    if(k>=depth[x]){
        return -1;
    }
    ll anc=x;
    for(int i=0;i<=LOG;i++){
        if(k&(1ll<<i)){
            anc=dp[anc][i];
        }
    }
    return anc;
}
