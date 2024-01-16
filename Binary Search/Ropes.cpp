#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,k;cin>>n>>k;
    vector<int>v(n);
    for(auto &it:v) cin>>it;
    double l=0,r=1e7+15;
    int loop=100;
    while (loop)
    {
        double mid=l+(r-l)/2;
        //fx
        int temp=0;
        for (int i = 0; i < n; i++)
        {
            temp+=floor(v[i]/mid);
        }
        if(temp>=k) l=mid;
        else r=mid;
        loop--;
        
    }
    cout<<setprecision(10)<<l<<"\n";
}
