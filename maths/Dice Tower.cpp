#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<long long int>v(n);
    for (int i = 0; i <n; i++)
    {
        cin>>v[i];
    }
    long long int div=0;
    for (int i = 0; i <n; i++)
    {
        div=v[i]/14;
        div--;
        if(div>-1)
        v[i]=v[i]-(div*14);
        if(v[i]>=15 and v[i]<=20) puts("YES");
        else puts("NO");
    }
}

