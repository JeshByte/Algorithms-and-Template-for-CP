#include<bits/stdc++.h>
using ll=int;
class DSU{
    vector<ll>parent,rank;
    public:
    DSU(ll n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    ll findParent(ll v){
        if(v==parent[v]){
            return v;
        }
        return parent[v]=findParent(parent[v]);
    }
    void Union(ll u,ll v){
        ll pu=findParent(u);
        ll pv=findParent(v);
        if(pu==pv){
            return;
        }
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  vector<pair<int,pair<int,int>>> comp;
  for(int i=0;i<edges.size();i++){
    comp.push_back({edges[i][2],{edges[i][0],edges[i][1]}});
  }
  DSU* d=new DSU(n);
  sort(comp.begin(),comp.end());
  int ans=0;
  for(int i=0;i<comp.size();i++){
    int u=comp[i].second.first;
    int v=comp[i].second.second;
    if(d->findParent(u)==d->findParent(v)){
      continue;
    }
    else{
      ans+=comp[i].first;
      d->Union(u,v);
    }
  }
  return ans;
}
