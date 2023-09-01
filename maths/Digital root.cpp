#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    long long k,x,ans;
    for (int i = 0; i <n; i++)
    {
        cin>>k>>x;   
        ans=x+(k-1)*9;
        cout<<ans<<"\n";
    }
}

