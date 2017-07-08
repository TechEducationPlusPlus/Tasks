#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
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
        string fname = "test-2." + toString(i);
        ofstream inp;
        inp.open(fname + ".in");
        int n = rand() % 100 + 1;
        inp << n << endl;
        for (int j = 1; j <= n; ++ j)
        {
            int dig = rand() % 6 + 1;
            int num = rand() * rand() + rand();
            if (num < 0) num *= -1;
            while (dig != 0)
            {
                inp << num % 10;
                num /= 10;
                dig--;
            }
            inp << ' ';
        }
        inp << endl;
        inp.close();
        string command = "task-2 < " + fname + ".in > " + fname + ".sol";
        system(command.c_str());
    }
    return 0;
}

