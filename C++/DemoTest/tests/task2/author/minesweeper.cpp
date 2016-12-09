//Task: minesweeper
//Author: Bistra Taneva
#include<iostream>
using namespace std;
int main()
{
    int a1, a2, a3, b1, b2, b3, c1, c2, c3;
    cin>>a1>>a2>>a3;
    cin>>b1>>b2>>b3;
    cin>>c1>>c2>>c3;
    if(a1!=9)
    {
        if(a2==9)a1++;
        if(b1==9)a1++;
        if(b2==9)a1++;
    }
    if(a2!=9)
    {
        if(a1==9)a2++;
        if(a3==9)a2++;
        if(b1==9)a2++;
        if(b2==9)a2++;
        if(b3==9)a2++;
    }
    if(a3!=9)
    {
        if(a2==9)a3++;
        if(b2==9)a3++;
        if(b3==9)a3++;
    }
    if(b1!=9)
    {
        if(a2==9)b1++;
        if(c2==9)b1++;
        if(b2==9)b1++;
        if(a1==9)b1++;
        if(c1==9)b1++;
    }
    if(b2!=9)
    {
        if(a1==9)b2++;
        if(a2==9)b2++;
        if(a3==9)b2++;
        if(b1==9)b2++;
        if(b3==9)b2++;
        if(c1==9)b2++;
        if(c2==9)b2++;
        if(c3==9)b2++;
    }
    if(b3!=9)
    {
        if(a2==9)b3++;
        if(b2==9)b3++;
        if(c2==9)b3++;
        if(a3==9)b3++;
        if(c3==9)b3++;
    }
    if(c1!=9)
    {
        if(c2==9)c1++;
        if(b1==9)c1++;
        if(b2==9)c1++;
    }
    if(c2!=9)
    {
        if(b3==9)c2++;
        if(b1==9)c2++;
        if(b2==9)c2++;
        if(c1==9)c2++;
        if(c3==9)c2++;
    }
    if(c3!=9)
    {
        if(c2==9)c3++;
        if(b3==9)c3++;
        if(b2==9)c3++;
    }
    cout<<a1<<" "<<a2<<" "<<a3<<endl;
    cout<<b1<<" "<<b2<<" "<<b3<<endl;
    cout<<c1<<" "<<c2<<" "<<c3<<endl;
    return 0;
}
