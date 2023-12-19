#include <bits/stdc++.h>
using namespace std;
typedef long long int llt;
llt w, h, n;

bool good(llt x)
{
    return (x / w) * (x / h) >= n;
}

int main()
{
    cin >> w >> h >> n;
    llt l = 0, r = 1;
    int count=0;
    while (!good(r))
    {
        r *= 2;
        count++;
    }
    
    llt mid = 0;
    while (l + 1 < r)
    {
        mid = l + (r - l) / 2;
        if (good(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << r<< "\n";
}
