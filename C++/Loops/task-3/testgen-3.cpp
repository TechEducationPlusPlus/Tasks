#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

string toString(int x)
{
    string s = "";
    s = (char)(x % 10 + 48) + s;
    x /= 10;
    s = (char)(x % 10 + 48) + s;
    return s;
}

int main()
{
    srand(time(0));

    for (int i = 1; i <= 10; ++ i)
    {
        string fname = "test-3." + toString(i);
        ofstream inp;
        inp.open(fname + ".in");
        int n = rand() % 100 + 1, m = 0;
        int maxblock = rand() % 10 + 1;
        inp << n << endl;
        int a[128];
        for (int j = 0; j < n; ++ j)
        {
            a[j] = rand() % 100 + 1;
        }
        while (m < n)
        {
            int block = rand() % maxblock + 1;
            sort(a + m, a + min(m + block, 100));
            m += block;
        }
        for (int j = 0; j < n; ++ j)
        {
            inp << a[j] << ' ';
        }
        inp << endl;
        inp.close();
        string command = "task-3 < " + fname + ".in > " + fname + ".sol";
        system(command.c_str());
    }
    return 0;
}


