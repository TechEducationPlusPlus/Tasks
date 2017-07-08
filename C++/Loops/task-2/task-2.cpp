#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++ i)
    {
        int x, sum = 0;
        cin >> x;

        while (x != 0)
        {
            sum += x % 10;
            x /= 10;
        }
        cout << sum << ' ';
    }

    cout << endl;
    return 0;
}
