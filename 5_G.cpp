#include<iostream>
#include<cmath>
#include<set>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

const long long MOD = 1e9+7;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, i, j, k, a, b, maxx=20000000, l=0, r, mid, x, y, z, m, s3=0, d, t, ans, p, cnt1, cnt2;
    cin >> cnt1 >> cnt2 >> x >> y;
    l = 1;
    r = 1e18;
    while (r - l > 1) {
        mid = (l + r) / 2;
        a = mid - mid / x;
        b = mid - mid / y;
        k = mid - mid / x - mid / y + mid / (x * y);
        if ((a >= cnt1) && (b >= cnt2) && (a + b - k >= cnt1 + cnt2)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r;
}