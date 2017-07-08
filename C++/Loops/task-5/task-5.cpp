#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++ i)
    {
        for (int j = 1; j <= n; ++ j)
        {
            if (i == j or j == n - i + 1 or i == n / 2 + 1 or j == n / 2 + 1) cout << '*';
            else cout << '.';
        }
        cout << endl;
    }

    return 0;
}
