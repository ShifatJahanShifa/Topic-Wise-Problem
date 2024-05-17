#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MOD=1e9+7;

vector<int>primes;

void sieve1(int n) 
{
    vector<int>marked(n+1,0);
    marked[0]=marked[1]=1;
    for (int i = 2; i*i<=n; i++)
    {
        if(marked[i]) continue;
        for (int j =i*i; j <=n; j+=i)
        {
            marked[j]=1;
        }
    }
    for (int i = 2; i <=n; i++)
    {
        if(!marked[i]) primes.push_back(i);
    }
}

int main()
{
    //q.2: find out prime numbers within a range;
    int n;
    cin>>n;
    sieve1(n);

    cout<<"prime divisors: \n";
    for (int i = 0; i <primes.size(); i++)
    {
        cout<<primes[i]<<" ";
    }
    cout<<"\n";
}
