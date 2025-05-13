vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<pair<int,int>> adj[vertices];
    for(int i=0;i<edges;i++){
        adj[vec[i][0]].push_back({vec[i][1],vec[i][2]});
        adj[vec[i][1]].push_back({vec[i][0],vec[i][2]});
    }
    vector<int> dist(vertices,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[source]=0;
    pq.push({0,source});
    while(!pq.empty()){
        pair<int,int> p=pq.top();
        pq.pop();
        for(auto it:adj[p.second]){
            int temp=p.first+it.second;
            if(temp<dist[it.first]){
                dist[it.first]=temp;
                pq.push({temp,it.first});
            }
        }
    }
    return dist;
}
