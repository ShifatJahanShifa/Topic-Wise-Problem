#include <bits/stdc++.h>
using namespace std;

// white 0 not discovered, gray 1 means discovered, black 2 visited and processed 

int main() 
{
	int n;cin>>n;
	int u,v;
	vector<vector<int>>graph(n+1);
	vector<set<int>>level(n+1);
	vector<int>color(n+1,0);  

	for (int i = 0; i <n-1; i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int x;cin>>x;

	vector<int>parentlevel(n+1);
	queue<int>queue;
	queue.push(1);
	color[1]=1;
	parentlevel[1]=1;
	level[1].insert(1);
	int l=2;
	while (!queue.empty())
	{
		u=queue.front();

		for (int i = 0; i < graph[u].size(); i++)
		{
			v=graph[u][i];
			if(color[v]==0) 
			{
				queue.push(v);
				parentlevel[v]=parentlevel[u]+1;
				int t=parentlevel[v];
				level[t].insert(v);
				color[v]=1;
			}
		}
		color[u]=2;
		queue.pop();
		l++;
	}
	
	cout<<level[x].size()<<"\n";
}
