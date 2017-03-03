//Task: basketball
//Author: Valentina Spasova
#include <iostream>
using namespace std;

int main()
{
    long long int n,p,k;
    cin >> n >> p >> k;
    long long int first = 0; //колко пъти е преброено първото дете
    long long int out = 0; //броят на децата, които излизат от кръга при съответното завъртане
    long long int basket = out; //броят на децата, които влизат в баскетболния отбор
    long long int ost = 0;//броят на останалите деца, които ще бъдат включени към следващото завъртане

    //броят на децата в кръга е не-по-малък от к
    while (n >= k && basket < p && ost < k-1)
    {
        out = (n + ost)/k;
        ost = (n + ost)%k;
        first++;
        basket += out;
        n = n - out;
    }
    if (basket >= p)
    {
        cout << first << endl << "VOLLEYBALL" << endl;
        return 0;
    }
    if (ost == k-1)
    {
        cout << first+1 << endl << "BASKETBALL" << endl;
        return 0;
    }

    //броят на децата в кръга е по-малък от к
    long long int last = 0;//поредният номер на последното преброено дете
    while (basket < p && last != 1)
    {
        first += (k - ost) / n;
        last = (k - ost) % n;
        if (last >= 1)
        {
            first++;
            ost = n - last;
        }
        else ost = 0;
        n--;
        basket++;
    }
    if (last == 1) cout << first << endl << "BASKETBALL" << endl;
    else cout << first << endl << "VOLLEYBALL" << endl;

return 0;
}
