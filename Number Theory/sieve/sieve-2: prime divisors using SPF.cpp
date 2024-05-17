#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MOD=1e9+7;
vector<int>SPF(1000000);

void sieve2(int n) 
{
    SPF.clear();
    for (int i = 2; i <=n; i++)
    {
        SPF[i]=i;
    }
    for (int i = 2; i*i<=n; i++)
    {
        if(SPF[i]!=i) continue;
        for (int j =i*i; j <=n; j+=i)
        {
            if(SPF[j]!=j) continue;
            SPF[j]=i;
        }
    }
}

int main()
{
    //q.4: find out prime divisors within a range and prime divisor of a number using SPF;
    int n;
    cin>>n;
    sieve2(n);
    int number;cin>>number;
    vector<int>pdivs;
    while (number>1)
    {
        pdivs.push_back(SPF[number]);
        number/=SPF[number];
    }
    cout<<"prime divisors: \n";
    for (int i = 0; i <pdivs.size(); i++)
    {
        cout<<pdivs[i]<<" ";
    }
    cout<<"\n";
}
