#include <bits/stdc++.h>
using namespace std;

// make it efficient plzzzzzz

vector<int>nodes;
int countNodes=0;
const int N=2e5+10;
vector<set<int>>r(N+1);
bitset<N>unvisited;   // joss part of the whole code

void DFS(int u)
{
    unvisited[u]=0;
    countNodes++;
    for(int i=unvisited._Find_first();i<unvisited.size();i=unvisited._Find_next(i)) 
    {
        if(!r[u].count(i)) 
        {
            DFS(i);
        }
    }
}

int main()
{
    int n,m,u,v;cin>>n>>m;
    for (int i = 0; i <m; i++)
    {
        cin>>u>>v;
        r[u].insert(v);
        r[v].insert(u);
    }
    for (int i = 1; i <=n; i++)
    {
        unvisited[i]=1;
    }
    
    int ccCount=0;
    for (int i = 1; i <=n; i++)
    {
        if(unvisited[i]) 
        {
            countNodes=0;
            DFS(i);
            ccCount++;
            nodes.push_back(countNodes);
        }
    }

    sort(nodes.begin(),nodes.end());
    cout<<ccCount<<"\n";
    for (int i = 0; i <ccCount; i++)
    {
        cout<<nodes[i]<<" ";
    }
    puts("");
}
