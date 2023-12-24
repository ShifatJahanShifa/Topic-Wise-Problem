// binary search on solution
#include <bits/stdc++.h>
using namespace std;
typedef int long long llt;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;cin>>n;
        llt x;cin>>x;
        vector<llt>a(n);
        for(auto &it:a) cin>>it;
        llt l=1,r=2e9+10;
        while (l+1LL<r)
        {
            llt mid=l+(r-l)/2;
            llt total=0;
            for (int i = 0; i <n; i++)
            {
                total+=max(0LL,mid-a[i]);
            }
            if(total>x) r=mid;
            else l=mid;
        }
        
        cout<<l<<"\n";
    }
}
