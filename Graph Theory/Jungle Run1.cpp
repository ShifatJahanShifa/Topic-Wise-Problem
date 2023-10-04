#include <bits/stdc++.h>
using namespace std;

// white 0 not discovered, gray 1 means one type, black 2 means another type

int n;
int arr[50][50], color[50][50];
vector<int> dx{-1, 0, 1, 0};
vector<int> dy{0, 1, 0, -1};
int ans = INT_MAX;

bool isValid(int x, int y)
{
    if ((x > -1 and x < n) and (y > -1 and y < n))
    {
        return true;
    }
    return false;
}

void DFS(vector<vector<char>> &g, int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int xp = x + dx[i];
        int yp = y + dy[i];
        if (isValid(xp, yp))
        {
            if (color[xp][yp] == 0 and g[xp][yp] == 'P')
            {
                arr[xp][yp] = arr[x][y] + 1;
                color[xp][yp] = 1;
                DFS(g,xp,yp);
                color[xp][yp]=0;
            }
            else if (g[xp][yp] == 'E')
            {
              //  cout<<ans<<" here \n";
                ans = min(ans, (arr[x][y] + 1));
                return ;
            }
        }
    }
   // color[x][y]=2;
}

int main()
{
    cin >> n;
    char ch;
    vector<vector<char>> graph(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ch;
            graph[i].push_back(ch);
            arr[i][j] = 0;
            color[i][j] = 0;
        }
    }

    int l = 2, x, y;
    DFS(graph,0,0);
    cout << ans << "\n";
}
