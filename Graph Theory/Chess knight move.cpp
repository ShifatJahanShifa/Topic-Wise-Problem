#include <bits/stdc++.h>
using namespace std;

// white 0 not discovered, gray 1 means one type, black 2 means another type

bool isValid(int x, int y)
{
    if ((x > -1 and x < 8) and (y > -1 and y < 8))
    {
        return true;
    }
    return false;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        int sx, sy, tx, ty;
        sx = s[1] - '1', tx = t[1] - '1';
        sy = s[0] - 'a', ty = t[0] - 'a';
        vector<vector<int>> graph(8);
        vector<vector<int>> isVisited(8, vector<int>(8,0));
        vector<int>dx{-2,-2,-1,1,2,2,1,-1};
        vector<int>dy{-1,1,2,2,1,-1,-2,-2};
        bool isPossible = true;
        vector<vector<int>>level(8, vector<int>(8,0));
        queue<pair<int, int>> queue;
        queue.push(make_pair(sx, sy));
        int x,y,path;
        while (!queue.empty())
        {
            x = queue.front().first;
            y = queue.front().second;
            if(x==tx and y==ty) 
            {
                path=level[x][y];
                break;
            }
            for (int i = 0; i < 8; i++)
            {
                int xp = x + dx[i];
                int yp = y + dy[i];
                if (isValid(xp, yp))
                {
                    if (isVisited[xp][yp] == 0)
                    {
                        queue.push(make_pair(xp, yp));
                        level[xp][yp] = level[x][y] + 1;
                        isVisited[xp][yp] = 1;
                    }
                }
            }
            queue.pop();
        }
        cout << path << "\n";
    }
}

// bfs on grid
/*
    while (!queue.empty())
    {
        x = queue.front().first;
        y = queue.front().second;
        for (int i = 0; i < 4; i++)
        {
            int xp = x + dx[i];
            int yp = y + dy[i];
            if (isValid(xp, yp))
            {
                if (color[xp][yp] == 0 and graph[xp][yp] == '.')
                {
                    queue.push(make_pair(xp, yp));
                    arr[xp][yp] = arr[x][y] + 1;
                    color[xp][yp] = 1;
                }
                else if (graph[xp][yp] == 'E')
                {
                    ans = min(ans, (arr[x][y] + 1));
                }
            }
        }
        color[x][y] = 2;
        queue.pop();


    }

    cout << ans << "\n";
    
    
    on graph 
    
     while (!queue.empty())
        {
            u = queue.front();
            for (int i = 0; i < graph[u].size(); i++)
            {
                v = graph[u][i];
                if (color[v] == 0)
                {
                    if (color[u] == 1)
                        color[v] = 2;
                    else
                        color[v] = 1;
                    queue.push(v);
                }
                else if (color[v] == color[u])
                {
                    isPossible = false;
                    break;
                }
            }
            queue.pop();
        }

        if (isPossible)
        {
            puts("YES");
            string ans;
            for (int i = 0; i < vp.size(); i++)
            {
                u = vp[i].first;
                v = vp[i].second;
                if (color[u] == 1 and color[v] == 2)
                    ans += '0';
                else
                    ans += '1';
            }
            cout << ans << "\n";
        }
        else
        {
            puts("NO");
        }*/
