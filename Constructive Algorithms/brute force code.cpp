#include <bits/stdc++.h>
using namespace std;

bool checkP(vector<int>&vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i+1; j < vec.size(); j++)
        {
            for (int k = j+1; k <vec.size(); k++)
            {
                if((vec[j]-vec[i])==(vec[k]-vec[j])) return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for (int i = 0; i <n; i++)
    {
        v[i]=i+1;
    }
    int cnt=0;
    while (next_permutation(v.begin(),v.end()))
    {
        if(checkP(v))
        {
            for (int i = 0; i <n; i++)
            {
                cout<<v[i]<<" ";
            }
            cout<<"\n";
            puts("---------");
        }
    }
}
