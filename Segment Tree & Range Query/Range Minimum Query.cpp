#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

vector<vector<int>> preprocess(vector<int>v)
{
    int n=v.size();
    int col=log2(n)+1;
    //int sparse[n][col];
    vector<vector<int>>sparse(n,vector<int>(col));
    for (int i = 0; i <n; i++)
    {
        sparse[i][0]=i;
    }
    for (int j = 1; (1<<j)<=n; j++)
    {
        for (int i = 0; i+(1<<j)-1<n; i++)
        {
            if(v[sparse[i][j-1]]<v[sparse[i+(1<<(j-1))][j-1]])
            sparse[i][j]=sparse[i][j-1];
            else sparse[i][j]=sparse[i+(1<<(j-1))][j-1];
        }
    }
    return sparse;
}

int main()
{
    int n,q;cin>>n>>q;
    vector<int>v(n);
    for(auto &itr:v) cin>>itr;
    auto it=preprocess(v);
    
    int l,r;
    while (q--)
    {
        cin>>l>>r;
        int dif=r-l+1;
        int k=log2(dif);
        //cout<<v[it[l-1][k]]<<" "<<v[it[l-1+dif-(1<<k)][k]]<<"\n";
        cout<<min(v[it[l-1][k]],v[it[l-1+dif-(1<<k)][k]])<<"\n";   
    }
}
