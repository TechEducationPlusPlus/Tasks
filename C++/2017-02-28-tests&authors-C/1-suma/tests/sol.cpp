#include <iostream>
#include <algorithm>

using namespace std;

int dp [1000000];
int a [1000000];

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int max_sum = 0, si = -1, ei = -1;
	int curr_sum = 0, si_cs = 0;
	for (int i = 0 ; i < n ; i ++)
	{
		cin >> a [i];
		curr_sum += a [i];
		if (max_sum <= curr_sum)
		{
				max_sum = curr_sum;
				si = si_cs;
				ei = i;
		}
		if (curr_sum < 0)
		{
				curr_sum = 0;
				si_cs = i + 1;
		}
	}
	if (max_sum == 0 and si == -1 and ei == -1)
	{
			cout    << *max_element (a, a + n) 
					<< " " << max_element (a, a + n) - a + 1
					<< " " << max_element (a, a + n) - a + 1 << endl; 
	}
	else
	{
			cout << max_sum << " " << si + 1 << " " << ei + 1 << endl;
	}
}

