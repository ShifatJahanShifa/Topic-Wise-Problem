#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
vector<ll>fact(1000005,1LL);

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


ll finalRes(ll a,ll b)
{
    if(a>=b) return (a-b)%mod;
    else return (mod+mod+a-b)%mod;
}

ll ncr(ll n,ll r)
{
    ll ans=1LL;
    // for n neing large or greater than 1e6
    // for (ll i = 0; i <r; i++)
    // {
    //     ans=(ans*(n-i))%mod;
    //     ans=(ans*BE(i+1LL,mod-2LL))%mod;
    // }
    // return ans;

    // for n being less than or equal to 1e6
    ll x=fact[n];
    ll y=fact[r];
    ll z=fact[n-r];
    ll p=(z*y)%mod;
    ans=(x*BE(p,mod-2))%mod;
    return ans;
}

void factorial()
{
    for (ll i = 2; i < 1000005; i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
}

int main()
{
    factorial();
    int T;cin>>T;
    while (T--)
    {
        ll n,k;cin>>n>>k;
        cout<<(ncr(n,k)*BE(2LL,k))%mod<<"\n";
    }
    
}
