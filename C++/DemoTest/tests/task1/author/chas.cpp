//Task: chas
//Author: Zornica Dzhenkova

#include <iostream>
using namespace std;
int main()
{ int t1,t2,m1,m2,ch,min,rez;
  cin>>t1>>m1>>t2>>m2;
  if(t1<t2)  ch = t2-t1-1; 
  else  ch = 23-t1+t2;
   min = 60-m1+m2; 
  if (t1==t2 && m1<m2) 
  { ch = 0; min = m2-m1;}
  if(t1==t2 && m1 == m2) 
  { ch = 0; min = 0;}
  rez = ch*60 + min;
  cout<<rez<<" ";
  cout<<rez/30<<endl;
}
