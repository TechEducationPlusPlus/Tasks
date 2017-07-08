#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int len = 0, maxl = 0, s, f;
    int x, y = 0, z = 0;

    for (int i = 1; i <= n; ++ i)
    {
        cin >> x;

        if (z == 0) z = x;

        if (y < x)
        {
            len++;
        }
        else
        {
            if (maxl < len)
            {
                maxl = len;
                s = z;
                f = y;
            }
            z = x;
            len = 1;
        }
        y = x;
    }

    if (maxl < len)
    {
        maxl = len;
        s = z;
        f = x;
    }

    cout << maxl << ' ' << s + f << endl;
    return 0;
}
