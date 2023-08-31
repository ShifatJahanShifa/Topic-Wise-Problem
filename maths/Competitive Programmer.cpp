#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    string input;
    for (int i = 0; i <n; i++)
    {
        cin>>input;
        int sum=0,cnte=0;
        bool oke=false,okz=false;
        for (int j = 0; j < input.size(); j++)
        {
            sum+=input[j]-'0';
            if((input[j]-'0')==0) okz=true;
            if((input[j]-'0')%2==0) cnte++;
        }
        if(sum==0) puts("red");
        else if((sum%3==0) and okz and cnte>=2) puts("red");
        else puts("cyan");
    }
}

