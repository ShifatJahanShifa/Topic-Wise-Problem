#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(auto &it:v) cin>>it;
    sort(v.begin(),v.end());
    int k,l,r;cin>>k;
    for (int i = 0; i < k; i++)
    {
        cin>>l>>r;
        // using lower_bound and upper_bound function
        int left=lower_bound(v.begin(),v.end(),l)-v.begin();
        int right=upper_bound(v.begin(),v.end(),r)-v.begin();
        cout<<right-left<<" ";
    }
    puts("");
}
