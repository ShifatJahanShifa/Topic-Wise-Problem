#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int T;cin>>T;
    while (T--)
    {
        int n,d,k;cin>>n>>k;
        vector<ll>v(n),preprocess(n,0);
        for(auto &it:v) cin>>it;
        map<ll,ll>mp;
        for (int i = 0; i <n; i++)
        {
            ll a=i+1LL;
            ll b=n-i;
            b*=1LL;
            a*=b;
            a--;
            mp[a]++;    
        }
        for (int i = 0; i <n-1; i++)
        {
            if((v[i]+1)!=v[i+1]) 
            {
                ll gap=v[i+1]-v[i];
                gap--;
                ll a=i+1LL;
                ll b=n-a;
                a*=b;
                mp[a]+=gap;
            }
        }
        ll qr;
        for (int i = 0; i <k; i++)
        {
            cin>>qr;
            cout<<mp[qr]<<" ";
        }
        cout<<"\n";
    }   
}
