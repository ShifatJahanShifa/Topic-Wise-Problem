#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v{1,2,3,4,5,6,7};
    for (int i = 0; i <7; i++)
    {
        cout<<v[i]<<" ";
    }
    puts("");
    // suppose i want to insert 8 before 5. it is expected that insert(pos, value) will insert 
    // the value at the given position. actually i will provide the position in 0 based index where i want to insert the value
    v.insert(v.begin()+4,8);
    for (int i = 0; i <8; i++)
    {
        cout<<v[i]<<" ";
    }
    puts("");
}
