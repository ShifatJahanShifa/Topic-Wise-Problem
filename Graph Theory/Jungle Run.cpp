#include <bits/stdc++.h>
using namespace std;

// white 0 not discovered, gray 1 means one type, black 2 means another type

int n;
bool isValid(int x,int y)
{
    if((x>-1 and x<n) and (y>-1 and y<n)) 
    {
        return true;
    }
    return false;
}

int main()
{
    cin >> n ;
    char ch;
    vector<vector<char>> graph(n); 
    int arr[n][n],color[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <n; j++)
        {
            cin>>ch;
            graph[i].push_back(ch);
            arr[i][j]=0;
            color[i][j]=0;
        }
    }

    int ans=INT_MAX;
    queue<pair<int,int>> queue;
    queue.push(make_pair(0,0));
    arr[0][0] = 0;
    int l = 2,x,y;
    vector<int>dx{-1,0,1,0};
    vector<int>dy{0,1,0,-1};

    while (!queue.empty())
    {
        x = queue.front().first;
        y = queue.front().second;
        for (int i = 0; i < 4; i++)
        {
            int xp=x+dx[i];
            int yp=y+dy[i];
            if(isValid(xp,yp)) 
            {
                if(color[xp][yp]==0 and graph[xp][yp]=='P')
                {
                    queue.push(make_pair(xp,yp));
                    arr[xp][yp] = arr[x][y] + 1;
                    color[xp][yp] = 1;
                }
                else if(graph[xp][yp]=='E') 
                {
                    ans=min(ans,(arr[x][y]+1));
                }
            }
        }
        color[x][y] = 2;
        queue.pop();
    }

    cout<<ans<<"\n";
}
