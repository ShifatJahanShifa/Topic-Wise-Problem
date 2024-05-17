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
    //q.3: find out prime divisors within a range and prime divisor of a number;
    int n;
    cin>>n;
    sieve1(n);
    int number;cin>>number;
    vector<int>pdivs;
    for (int i = 0; i <primes.size(); i++)
    {
        while (number%primes[i]==0)
        {
            pdivs.push_back(primes[i]);
            number/=primes[i];
        }
        if(number==1) break;
    }
    
    cout<<"prime divisors: \n";
    for (int i = 0; i <pdivs.size(); i++)
    {
        cout<<pdivs[i]<<" ";
    }
    cout<<"\n";
}
