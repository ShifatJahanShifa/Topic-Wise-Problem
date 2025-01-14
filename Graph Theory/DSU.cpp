#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int>parent,rank_;

void initialize(int n)
{
    rank_.resize(n+1,0);
    parent.resize(n+1,0);
    for (int i = 0; i <=n; i++)
    {
        parent[i]=i;
    }
}

int findUltimateParent(int n)
{
    if(n==parent[n]) return n;
    parent[n]=findUltimateParent(parent[n]);
    return parent[n];
}

void unionByRank(int u,int v)
{
    int ulp_u=findUltimateParent(u);
    int ulp_v=findUltimateParent(v);
    if(ulp_u==ulp_v) return;
    if(rank_[ulp_u]<rank_[ulp_v]) 
    {
        parent[ulp_u]=ulp_v;
    }
    else if(rank_[ulp_v]<rank_[ulp_u])
    {
        parent[ulp_v]=ulp_u;
    }
    else 
    {
        parent[ulp_u]=ulp_v;
        rank_[ulp_v]++;
    }
}

int main()
{
    // initialize
    int n,e; cin>>n>>e;
    initialize(n);
    int u,v;
   
    unionByRank(1,3);
    unionByRank(2,4);

    if(parent[1]==parent[4])
    {
        cout<<"in the same component\n";
    }
    else cout<<"not in the same component\n";
    unionByRank(2,3);
    if(parent[1]==parent[4])
    {
        cout<<"in the same component\n";
    }
    else cout<<"not in the same component\n";
}
