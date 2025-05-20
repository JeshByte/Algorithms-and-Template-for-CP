#include<bits/stdc++.h>
void dfs(int v, vector<bool>& visited, stack<int>& st, vector<int> adj[]){
	visited[v]=true;
	for(auto it:adj[v]){
		if(!visited[it]){
			dfs(it,visited,st,adj);
		}
	}
	st.push(v);
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	vector<int> adj[v];
	for(int i=0;i<edges.size();i++){
		adj[edges[i][0]].push_back(edges[i][1]);
	}
	stack<int> st;
	vector<bool> visited(v,false);
	for(int i=0;i<v;i++){
		if(!visited[i]){
			dfs(i,visited,st,adj);
		}
	}
	for(int i=0;i<v;i++){
		adj[i].clear();
	}
	for(int i=0;i<edges.size();i++){
		adj[edges[i][1]].push_back(edges[i][0]);
	}
	int ans=0;
	fill(visited.begin(),visited.end(),false);
	stack<int> dummy;
	while(!st.empty()){
		int u=st.top();
		st.pop();
		if(visited[u]){
			continue;
		}
		dfs(u,visited,dummy,adj);
		ans++;
	}
	return ans;
}
