#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n; cin>>n;
    int arr[n][n][n],prefix[n+1][n+1][n+1];
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j <n; j++)
        {
            for (int k =0; k <n; k++)
            {
                cin>>arr[i][j][k];
            }
        }
    }
    // calculate prefix sum
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j <n; j++)
        {
            for (int k =0; k <n; k++)
            {
                prefix[i][j][k]=0;
            }
        }
    }
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j <n; j++)
        {
            for (int k =0; k <n; k++)
            {
                prefix[i+1][j+1][k+1]=prefix[i][j+1][k+1]+prefix[i+1][j][k+1]+prefix[i+1][j+1][k]-
                prefix[i][j][k+1]-prefix[i][j+1][k]-prefix[i+1][j][k]+prefix[i][j][k]+arr[i][j][k];
            }
        }
    }

    // performing range sum
    int q;cin>>q;
    int lx,rx,ly,ry,lz,rz;
    while (q--)
    {
        cin>>lx>>rx>>ly>>ry>>lz>>rz;
        int ans=0;
        ans=prefix[rx][ry][rz]-prefix[lx-1][ry][rz]-prefix[rx][ly-1][rz]-prefix[rx][ry][lz-1]+prefix[lx-1][ly-1][rz]+
        prefix[lx-1][ry][lz-1]+prefix[rx][ly-1][lz-1]-prefix[lx-1][ly-1][lz-1];
        cout<<ans<<"\n";
    }
    
}
