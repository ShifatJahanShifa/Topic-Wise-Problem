#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n, int m)
{
	if ((x > -1 and x < n) and (y > -1 and y < m))
	{
		return true;
	}
	return false;
}

bool isEdge(int x, int y, int n, int m)
{
	return (x == 0 or x == (n - 1) or y == 0 or y == (m - 1));
}

int main()
{
	int n, m, e;
	cin >> n >> m;
	vector<vector<int>> graph(n, vector<int>(m));
	bool isVisited[n][m];
	int level[n][m];
	int s1 = 0, s2 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> e;
			graph[i][j] = e;
			if (e == 2)
				s1 = i, s2 = j;
			isVisited[i][j] = false;
			level[i][j] = 0;
		}
	}

	vector<int> dx{-1, 0, 1, 0};
	vector<int> dy{0, 1, 0, -1};
	queue<pair<int, int>> queue;
	level[s1][s2] = 0;
	queue.push({s1, s2});
	isVisited[s1][s2] = 1;
	int x, y;
	bool edge = false;
	int path = -1;
	while (!queue.empty())
	{
		x = queue.front().first;
		y = queue.front().second;

		if (isEdge(x, y, n, m))
		{
			path = level[x][y];
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int xp = x + dx[i];
			int yp = y + dy[i];
			if (isValid(xp, yp, n, m) and isVisited[xp][yp] == 0 and graph[xp][yp] == 0)
			{
				level[xp][yp] = level[x][y] + 1;
				queue.push(make_pair(xp, yp));
				isVisited[x][y] = 1;
			}
		}
		queue.pop();
	}

	// edge ? cout << path << "\n" : cout << "-1\n";
	cout << path << "\n";
}
