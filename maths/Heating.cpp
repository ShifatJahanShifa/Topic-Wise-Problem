#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    long long c,sum,ans,div;
    for (int i = 0; i <n; i++)
    {
        cin>>c>>sum;   
        ans=0;
        if(c>=sum)
        cout<<sum<<"\n";
        else 
        {
            div=sum/c;
            if(sum%c) 
            {
                long long mod=sum%c;
                for (int j= 1; j <=c; j++)
                {
                    if(j<=mod) ans+=(div+1)*(div+1);
                    else ans+=div*div;
                }
            }
            else 
            {
                for (int j = 0; j < c; j++)
                {
                    ans+=div*div;
                }
            }
            cout<<ans<<"\n";
        }
    }
}

