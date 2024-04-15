#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(auto &it:v) cin>>it;
    map<int,int>visited;
    int mex=0;
    for (int i = 0; i <n; i++)
    {
        visited[v[i]]=1;
        if(v[i]==mex) 
        {
            while (visited[mex])
            {
                mex++;
            }
        }
        cout<<mex<<" \n"[i==n-1];
    }
    
}