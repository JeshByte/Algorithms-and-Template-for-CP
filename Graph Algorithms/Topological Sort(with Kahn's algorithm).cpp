#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> adj[v];
    vector<int> indegree(v,0);
    for(int i=0;i<e;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        indegree[edges[i][1]]++;
    }
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int vertex=q.front();
        q.pop();
        ans.push_back(vertex);
        for(auto it:adj[vertex]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return ans;
}
