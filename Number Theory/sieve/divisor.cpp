#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MOD=1e9+7;

int main()
{
    //q.1: find out divisors of a number;
    int n;
    cin>>n;
    vector<int>divs;
    // i can go to sqrt(n). it is enough
    for (int i = 1; i*i<=n; i++)
    {
        if(n%i==0) 
        {
            divs.push_back(i);
            if(!(i*i==n)) divs.push_back(n/i);
        }
    }
    sort(divs.begin(),divs.end());
    cout<<"divisors: \n";
    for (int i = 0; i <divs.size(); i++)
    {
        cout<<divs[i]<<" ";
    }
    cout<<"\n";
}
