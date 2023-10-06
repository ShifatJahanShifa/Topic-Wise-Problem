#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>&g,int u,vector<bool>&visited)
{
    visited[u]=true;
    for(auto v:g[u]) 
    {
        if(!visited[v]) 
        {
            DFS(g,v,visited);
        }
    }
}

int main() 
{
	int n,e,u,v;cin>>n>>e;
    vector<vector<int>>graph(n+1);
    //bool isVisited[n+1]={false};
    vector<bool>isVisited(n+1, false);
    for (int i = 0; i <e; i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int ccCount=0;
    for (int i = 1; i <=n; i++)
    {
        if(!isVisited[i])
        {
            DFS(graph,i,isVisited);
            ccCount++;
        }
    }
    cout<<ccCount<<"\n";
}
