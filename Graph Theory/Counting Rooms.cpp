#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> dx{-1, 0, 1, 0};
vector<int> dy{0, 1, 0, -1};

bool isValid(int x, int y)
{
    if ((x > -1 and x < n) and (y > -1 and y < m))
    {
        return true;
    }
    return false;
}

void DFS(vector<vector<int>> &g, int x,int y, vector<vector<bool>> &visited)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int xp=x+dx[i];
        int yp=y+dy[i];
        if(isValid(xp,yp)) 
        {
            if(g[xp][yp]=='.' and !visited[xp][yp]) 
            {
                DFS(g,xp,yp,visited);
            }
        }
    }
}

int main()
{
    int u, v;
    cin >> n >> m;
    char ch;
    vector<vector<int>> graph(n,vector<int>(m));
    // bool isVisited[n+1]={false};
    vector<vector<bool>> isVisited(n,vector<bool>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ch;
            graph[i][j]=ch;
            isVisited[i][j]=false;
        }
    }

    int ccCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j]=='.' and !isVisited[i][j])
            {
                DFS(graph, i,j, isVisited);
                ccCount++;
            }
        }
    }
    cout << ccCount << "\n";
}
