void dfs(vector<vector<ll>>&adj,ll n,ll v,stack<ll>&st,vector<bool>&visited){
    visited[v]=true;
    for(int i=1;i<=n;i++){
        if(adj[v][i]==1 && !visited[i]){
            dfs(adj,n,i,st,visited);
        }
    }
    st.push(v);
}
vector<ll> topologicalSort(vector<vector<ll>>&adj,ll n){
    vector<bool>visited(n+1,false);
    stack<ll>st;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(adj,n,i,st,visited);
        }
    }
    vector<ll>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
