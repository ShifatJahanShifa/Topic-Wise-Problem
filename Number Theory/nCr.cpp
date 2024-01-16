// calculate nCr efficiently

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n=25,r=5;
    // replacing r with smaller value
    if(n-r<r) r=n-r;
    ll up=1,down=1;
    if(r==0) cout<<1<<"\n";
    else 
    {
        while (r)
        {
            up*=n;
            down*=r;
            int gcd=__gcd(up,down);
            up/=gcd;
            down/=gcd;
            n--,r--;
        }
        cout<<up<<"\n";    // down will be 1 because ncr is natural number. so gcd diye katakati hoyei jabe
    }
}
