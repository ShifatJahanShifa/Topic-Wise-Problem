#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main()
{
    int T;cin>>T;
    while (T--)
    {
        int N,k;cin>>N>>k;
        vector<int>v(N);
        for(auto &it:v) cin>>it;
        deque<int>dq;
        for (int i = 0; i <k; i++)
        {
            while (!dq.empty() and v[i]>=v[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for (int i = k; i <N; i++)
        {
            cout<<v[dq.front()]<<" ";
            // index out
            while (!dq.empty() and dq.front()<=i-k)
            {
                dq.pop_front();
            }
            while (!dq.empty() and v[i]>=v[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        cout<<v[dq.front()]<<"\n";
    }
    
}
