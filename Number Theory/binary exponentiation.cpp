#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000000007;

ll BE(ll a,ll b)
{
    ll ans=1LL;
    while(b)
    {
        if(b%2LL) ans*=a;
        ans%=mod;
        a*=a;
        a%=mod;
        b/=2LL;
    }
    return ans;
}

int main()
{
    cout<<BE(2LL,4LL)<<"\n";
}
