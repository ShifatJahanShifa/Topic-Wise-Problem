//sample tuple code
#include<bits/stdc++.h>
using namespace std; 

int main()
{
  tuple<char,int,string>sample;
  sample=make_tuple('s',1301,"shifa");
  cout<<"printing the tuple\n";
  
  cout<<get<0>(sample)<<" ";
  cout<<get<1>(sample)<<" ";
  cout<<get<2>(sample)<<"\n";
  
  get<0>(sample)='a';
  get<2>(sample)="rini";
  
  cout<<get<0>(sample)<<" ";
  cout<<get<1>(sample)<<" ";
  cout<<get<2>(sample)<<"\n";
}
