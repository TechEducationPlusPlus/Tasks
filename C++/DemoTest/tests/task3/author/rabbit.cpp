//Task: rabbit
//Author: Suzan Feimova
#include<iostream>
using namespace std;
int main()

{  int x,n,d,m,g,p,p1;
   cin>>x>>n>>d>>m>>g;
  
   p1=n+2*n*(x-1);
   d=d+p1-1;
   
   if(m==2)
     {
      if(((g%4==0)&& (g%100!=0))||(g%400==0)) p=29;
        else p=28;
     }
     else
       {
        if((m==4)||(m==6)||(m==9)||(m==11)) p=30;
          else p=31;
       }
           
  if(d>p)
    {   
     d=d-p;
     if(m<12) {m++;}
       else {m=1; g++;} 
    }
        
  cout<<d<<" "<<m<<" "<<g<<endl;
  return 0;
}
