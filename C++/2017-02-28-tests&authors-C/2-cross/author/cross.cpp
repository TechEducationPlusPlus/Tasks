#include <iostream>
#include <cstdio>
#include <vector>

#define MAXN 1004

using namespace std;
struct Box
{
    int up, down, left, right;
    int it;
};
int n, m;
Box v[MAXN][MAXN];
void check (int x, int y)
{

    if (x == 1 || x == n || y == 1 || y == m)
    {
        cout << -1 << endl;
        return;
    }
    int br = v[x][y-1].it + v[x-1][y].it + v[x+1][y].it + v[x][y+1].it;
    int maxSum = v[x][y].up + v[x][y].down + v[x][y].left + v[x][y].right + 1;
    //printf("%d %d %d %d\n", v[x][y].up, v[x][y].down, v[x][y].left, v[x][y].right);
    if (br < 3 || (v[x][y].it == 0 && br == 3))
    {
        cout << -1 << endl;
        return;
    }
    else if (br == 3 || v[x][y].it == 0)
    {
        if (v[x][y].up == 0)
            maxSum += v[x-1][y].up + 1;
        if (v[x][y].down == 0)
            maxSum += v[x+1][y].down + 1;
        if (v[x][y].left == 0)
            maxSum += v[x][y-1].left + 1;
        if (v[x][y].right == 0)
            maxSum += v[x][y+1].right + 1;
    }
    else if (br == 4)
    {
        int moreUp = 0, moreDown = 0, moreLeft = 0, moreRight = 0;
        if (y + v[x][y].right + 1 <= m)
            moreRight = v[x][y+v[x][y].right+1].right + 1;
        if (y - v[x][y].left - 1 >= 1)
        {
            //printf("L:%d\n", y-v[x][y].left);
            moreLeft = v[x][y-v[x][y].left-1].left + 1;
        }
        if (x + v[x][y].down + 1 <= n)
            moreDown = v[x+v[x][y].down+1][y].down + 1;
        if (x - v[x][y].up - 1 >= 1)
            moreUp = v[x-v[x][y].up-1][y].up + 1;
        //printf("%d %d %d %d\n", moreUp, moreDown, moreLeft, moreRight);
        maxSum += max(max(moreUp, moreDown), max(moreLeft, moreRight));
    }
    cout << maxSum << endl;
}
int main ()
{
char ccc;
    scanf("%d%d", &n, &m);
    //v.resize(n+2);
    for (int i = 1; i <= n; i++)
    {
      //  v[i].resize(n+2);
        for (int j = 1; j <= m; j++)
        {
        	cin>>ccc;
//            scanf("%d", &v[i][j].it);
			v[i][j].it=ccc-'0';
            v[i][j].up = (v[i-1][j].up + 1) * v[i-1][j].it;
            v[i][j].left = (v[i][j-1].left + 1) * v[i][j-1].it;
        }
    }
    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--)
        {
            v[i][j].right = (v[i][j+1].right + 1) * v[i][j+1].it;
            v[i][j].down = (v[i+1][j].down + 1) * v[i+1][j].it;
        }

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        check(x, y);
    }
    return 0;
}
/*
5 5
1 1 1 1 1
1 1 1 1 1
1 1 1 0 1
1 0 1 1 1
1 0 0 1 1
1
2 3

7 11
11010010100
11011101110
01111111110
11110111111
01110101011
11111111011
01010100101

5 5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 0 1 1
1
3 3
*/
