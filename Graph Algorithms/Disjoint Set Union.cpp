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
};
