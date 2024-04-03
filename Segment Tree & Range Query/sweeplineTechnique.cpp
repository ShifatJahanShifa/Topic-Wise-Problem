#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int sz=1e5+5;

int main()
{
    int n,q;cin>>n>>q;
    vector<ll>v(sz,0);
    ll val;int l,r;
    while (n--)
    {
        cin>>l>>r>>val;
        v[l]+=val;
        v[r]-=val;
    }

    for (int i = 1; i <sz; i++)
    {
        v[i]+=v[i-1];
    }
    for (int i = 1; i <sz; i++)
    {
        v[i]+=v[i-1];
    }
    ll x;
    while (q--)
    {
        cin>>l>>r; 
        cout<<v[r-1]-v[l-1]<<"\n";
    }
}
