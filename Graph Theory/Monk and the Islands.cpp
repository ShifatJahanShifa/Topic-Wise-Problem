#include <bits/stdc++.h>
using namespace std;

// white 0 not discovered, gray 1 means discovered, black 2 visited and processed

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n,m;
		cin >> n>>m;
		int u, v;
		vector<vector<int>> graph(n + 1);
		vector<int> color(n + 1, 0);

		for (int i = 0; i < m; i++)
		{
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		vector<int> level(n + 1);
		queue<int> queue;
		queue.push(1);
		color[1] = 1;
		level[1] = 0;
		int l = 2;
		while (!queue.empty())
		{
			u = queue.front();
			for (int i = 0; i < graph[u].size(); i++)
			{
				v = graph[u][i];
				if (color[v] == 0)
				{
					queue.push(v);
					level[v] = level[u] + 1;
					color[v] = 1;
				}
			}
			color[u] = 2;
			queue.pop();
			l++;
		}

		cout << level[n] << "\n";
	}
}
