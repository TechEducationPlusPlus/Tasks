#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 2; i <= n; ++ i)
    {
        bool fl = true;
        for (int j = 2; j * j <= i; ++ j)
        {
            if (i % j == 0)
            {
                fl = false;
                break;
            }
        }
        if (fl) cout << i << ' ';
    }

    cout << endl;
    return 0;

}
