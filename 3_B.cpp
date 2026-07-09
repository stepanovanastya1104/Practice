#include<iostream>
#include<cmath>
#include<set>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, i, j, k, maxl, a, l=0, r, mid, x, y, ans=0, t=0, s=0, m;
    cin >> n >> k >> m;
    long long mod=1e9 + 7;
    vector<long long> dp(n + 1, 0), pref(n + 1, 0), danger(n + 1, 1);
    for (i = 1; i <= m; i++) {
        long long pos;
        cin >> pos;
        danger[pos] = 0;
    }
    dp[0] = 1;
    pref[0] = 1;
    for (i = 1; i <= n; ++i) {
        s = pref[i - 1];
        if (i - k - 1 >= 0) {
            s = (s - pref[i - k - 1] + mod) % mod;
        }
        dp[i] = s * danger[i] % mod;
        pref[i] = (pref[i - 1] + dp[i]) % mod;
    }
    cout << dp[n];
}