#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
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

    vector<int> primes;
    for (int i = 2; i <= 30; ++ i)
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
        if (fl) primes.push_back(i);
    }

    for (int i = 1; i <= 10; ++ i)
    {
        string fname = "test-4." + toString(i);
        ofstream inp;
        inp.open(fname + ".in");
        int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        random_shuffle(a, a + 10);
        int n = 1;
        for (int j = 0; j < 10 and n <= 1000000; ++ j)
        {
            int cnt = rand() % (10 - a[j]) + 1;
            if (a[j] > 4) cnt = 1;
            while (cnt != 0 and n <= 1000000)
            {
                n *= primes[a[j]];
                cnt--;
            }
        }
        if (rand() % 2 == 0) inp << n << endl;
        else
        {
            int r = (rand() * rand() + rand()) % 500000;
            if (r < 0) r = -r;
            inp << (r + 1) * 2 << endl;
        }
        inp.close();
        string command = "task-4 < " + fname + ".in > " + fname + ".sol";
        system(command.c_str());
    }
    return 0;
}



