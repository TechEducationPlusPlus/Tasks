#include<iostream>
using namespace std;

const int N=1000001;
int a[N];
int n;

int T[N];

int main()
{
  cin >> n;
  for(int i=0;i<n;i++) cin >> a[i];

  T[0]=a[0];

  for(int i=1;i<n;i++)
  {
    int s=a[i];
    int m=a[i];
    for(int j=i-1;j>=0;j--)
    {
      s += a[j];
      if(m<s)m=s;
    }
    T[i]=m;
  }


  int m=T[0];
  int i2=0;
  for(int i=1;i<n;i++)
    if(m<=T[i]) {m=T[i]; i2=i;}
  cout << m;
  //cout << endl;

  int i1=i2+1;
  int s=0;
  for(int i=i2;i>=0;i--)
  {
    s += a[i];
    if(s==m){i1=i;}
  }

  cout << " " << i1+1 << " " << i2+1 << endl;


}
