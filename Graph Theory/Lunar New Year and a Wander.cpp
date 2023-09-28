#include <bits/stdc++.h>
using namespace std;

// white 0 not discovered, gray 1 means discovered, black 2 visited and processed

int main()
{
    int n, m;
    cin >> n >> m;
    int u, v;
    vector<vector<int>> graph(n + 1);
    vector<int> color(n + 1, 0);
    vector<int> ans;
    color[1] = 1;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    priority_queue<int, vector<int>, greater<int>> queue;
    queue.push(1);

    while (!queue.empty())
    {
        u = queue.top();
        ans.push_back(u);
        queue.pop();
        for (int i = 0; i < graph[u].size(); i++)
        {
            v = graph[u][i];
            if (color[v] == 0)
            {
                queue.push(v);
                color[v] = 1;
            }
        }
        color[u] = 2;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    puts("");
}
