#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, val;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;
    bool ok;
    for (int i = 0; i < k; i++)
    {
        cin >> val;
        ok=false;
        // binary search implementation
        int left=0,right=n-1,mid=0;
        while (left<=right)
        {
            mid=left+(right-left)/2;
            if(v[mid]==val) 
            {
                ok=true;
                break;
            }
            if(v[mid]<val) 
            {
                left=mid+1;
            }
            else 
            {
                right=mid-1;
            }
        }
        ok ? puts("YES") : puts("NO");
    }
}
