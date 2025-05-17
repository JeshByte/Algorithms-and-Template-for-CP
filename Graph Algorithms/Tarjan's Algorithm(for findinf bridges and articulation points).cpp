void dfs(int v, int& timer, vector<int>& disc, vector<int>& low, vector<bool>& vis, int parent, 
vector<vector<int>>& ans, vector<int> adj[]){
    vis[v]=true;
    disc[v]=low[v]=timer++;
    for(auto it:adj[v]){
        if(it==parent){
            continue;
        }
        if(!vis[it]){
            dfs(it,timer,disc,low,vis,v,ans,adj);
            low[v]=min(low[it],low[v]);
            if(disc[v]<low[it]){
                ans.push_back({v,it});
            }
        }
        else{
            low[v]=min(low[v],disc[it]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    vector<int> adj[v];
    for(int i=0;i<e;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    int timer=0;
    vector<int> disc(v,-1);
    vector<int> low(v,-1);
    vector<bool> vis(v,false);
    int parent=-1;
    vector<vector<int>> ans;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,timer,disc,low,vis,parent,ans,adj);
        }
    }
    return ans;
}
