// codeforces

#include<bits/stdc++.h>
using namespace std;
long long int mod=1e9+7;

int main()
{
    int T;cin>>T;
    while (T--)
    {
        int n;cin>>n;
        vector<long long int>a(n),b(n);
        for(auto &it:a) cin>>it;
        for(auto &it:b) cin>>it;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end(),greater<long long int>());
        int ans=1;
        for (int i = 0; i <n; i++)
        {
            int cnt=(a.size()-(upper_bound(a.begin(),a.end(),b[i])-a.begin()));
            ans=((ans%mod)*(max((cnt-i),0))%mod)%mod;
        }
        cout<<ans<<"\n";
    }    
}
