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
        int left=-1,right=n,mid=0;
        while (left+1<right)
        {
            mid=left+(right-left)/2;
            if(v[mid]<val) 
            {
                left=mid;
            }
            else 
            {
                right=mid;
            }
        }
        cout<<right+1<<"\n";
    }
}
