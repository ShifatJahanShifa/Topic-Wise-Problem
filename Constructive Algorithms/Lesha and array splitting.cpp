#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(auto &it:v) cin>>it;
    int sum=0,mark;
    bool ok=false;
    for (int i = 0; i <n; i++)
    {
        sum+=v[i];
    }
    if(sum) 
    {
        puts("YES");
        puts("1");
        cout<<1<<" "<<n<<"\n";
    }
    else 
    {
        for (int i = 0; i <n; i++)
        {
            if(v[i])
            {
                mark=i+1;
                ok=true;
                break;
            }
        }
        if(ok) 
        {
            puts("YES");
            puts("2");
            cout<<1<<" "<<mark<<"\n"<<mark+1<<" "<<n<<"\n";
        }
        else puts("NO");
    }
}

