#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n, m; cin >> n >> m;
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        for (long long j = 2; j <= m; j++) {
            if (i*j+n-i==m) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
