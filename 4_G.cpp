
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

    long long n, i, j, k, maxx, l=0, r, mi, x, y, m, x1=0, x2=0, s3=0, pr, q, v, s=0, p, val, idx, cnt, diff;
    cin >> n >> m;
    if (n < m) {
        cout << 0;
        return 0;
    }
    vector<long long> a(n), b(m);
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < m; i++)
        cin >> b[i];
    vector<long long> need(101, 0), cur(101, 0);
    for (auto x : b)
        need[x]++;
    for (auto i = 0; i < m; i++)
        cur[a[i]]++;
    vector<long long> ans;
    bool ok = true;
    for (i = 1; i <= 100; i++) {
        if (need[i] != cur[i]) {
            ok = false;
            break;
        }
    }
    if (ok)
        ans.push_back(1);
    for (i = m; i < n; i++) {
        cur[a[i - m]]--;
        cur[a[i]]++;
        ok = true;
        for (j = 1; j <= 100; j++) {
            if (need[j] != cur[j]) {
                ok = false;
                break;
            }
        }
        if (ok)
            ans.push_back(i - m + 2);
    }
    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x << " ";
}