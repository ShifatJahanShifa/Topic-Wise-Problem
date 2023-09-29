#include <bits/stdc++.h>
using namespace std;

// white 0 not discovered, gray 1 means one type, black 2 means another type

int main()
{
    int n, m;
    cin >> n >> m;
    int u, v;
    vector<vector<int>> graph(n + 1);
    vector<int> color(n + 1, 0);
    vector<pair<int,int>>vp;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        vp.push_back(make_pair(u,v));
    }

    bool isPossible=true;
    queue<int> queue;
    queue.push(1);
    color[1] = 1;
    while (!queue.empty())
    {
        u = queue.front();
        for (int i = 0; i < graph[u].size(); i++)
        {
            v = graph[u][i];
            if (color[v] == 0)
            {
                if(color[u]==1)
                color[v] = 2;
                else color[v]=1;
                queue.push(v);
            }
            else if(color[v]==color[u]) 
            {
                isPossible=false;
                break;
            }
        }
        queue.pop();
    }

    if(isPossible) 
    {
        puts("YES");
        string ans;
        for (int i = 0; i < vp.size(); i++)
        {
            u=vp[i].first;
            v=vp[i].second;
            if(color[u]==1 and color[v]==2) ans+='0';
            else ans+='1';
        }
        cout<<ans<<"\n";
    }
    else
    {
        puts("NO");
    }
}
