#include<bits/stdc++.h>
using namespace std;

long long countDivs(long long n, long long maxDiv) {
    long long ans = 0;
    for (long long i = 1; i <= maxDiv && i*i <= n; i++) {
        if (n%i != 0) continue;

        ans++;
        long long d = n/i;
        if (d != i && d <= maxDiv) ans++;
    }
    return ans;
}

int main() {
    long long n, m; cin >> n >> m;
    long long ans = countDivs(m-n, n);
    cout << ans << endl;

    return 0;
}
