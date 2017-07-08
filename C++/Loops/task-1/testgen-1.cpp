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

int used[128];

int main()
{
    srand(time(0));

    for (int i = 1; i <= 10; ++ i)
    {
        string fname = "test-1." + toString(i);
        ofstream inp;
        inp.open(fname + ".in");
        int n;
        do
        {
            n = rand() % 98 + 3;
        }
        while (used[n] != 0);
        inp << n << endl;
        used[n] = 1;
        inp.close();
        string command = "task-1 < " + fname + ".in > " + fname + ".sol";
        system(command.c_str());
    }
    return 0;
}
