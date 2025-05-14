#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        adj[g[i].first.first].push_back({g[i].first.second,g[i].second});
        adj[g[i].first.second].push_back({g[i].first.first,g[i].second});
    }
    vector<int> key(n+1,INT_MAX);
    vector<bool> mst(n+1,false);
    vector<int> parent(n+1,-1);
    key[1]=0;
    for(int i=1;i<n;i++){
        int u=-1;
        int mini=INT_MAX;
        for(int j=1;j<=n;j++){
            if(mst[j]==false && key[j]<mini){
                u=j;
                mini=key[j];
            }
        }
        mst[u]=true;
        for(auto it:adj[u]){
            if(mst[it.first]==false && it.second<key[it.first]){
                key[it.first]=it.second;
                parent[it.first]=u;
            }
        }
    }
    vector<pair<pair<int, int>, int>> res;
    for(int i=2;i<=n;i++){
        res.push_back({{parent[i],i},key[i]});
    }
    return res;
}
