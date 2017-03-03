//Task: copying
//Author: Zornica Dzhenkova

#include<iostream>
using namespace std;

int main()
{
    int n,k,i=1,s=1,t=0;
    cin>>n>>k;

    while(i<k)
    {
        s=s+i;
        i=2*i;
        t++;
        if(s>=n) break;
    }

    while(s<n)
    {
        s=s+k;
        t++;
    }

   if (n==1) cout<<0<<endl;
   else cout<<t<<endl;
}

