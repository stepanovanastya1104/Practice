#include<iostream>
#include<cmath>
#include<set>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
 
const long long INF = 2e18;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    long long n, i, j, k, a, b, maxx=20000000, l=0, r, mid, x, y, z, m, s, d, t, ans, p, cnt1, cnt2;
    cin >> n >> m >> s;
    s--;
    vector<int> u(m), v(m);
    vector<long long> w(m);
    for (i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        u[i]--;
        v[i]--;
    }
    vector<long long> dist(n, INF);
    dist[s] = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < m; j++) {
            if (dist[u[j]] != INF && dist[v[j]] > dist[u[j]] + w[j])
                dist[v[j]] = dist[u[j]] + w[j];
        }
    }
    vector<long long> dist2 = dist;
    for (j = 0; j < m; j++) {
        if (dist2[u[j]] != INF && dist2[v[j]] > dist2[u[j]] + w[j]) {
            dist2[v[j]] = dist2[u[j]] + w[j];
        }
    }
    if (dist != dist2) {
        cout << "Negative cycle";
        return 0;
    }
    for (i = 0; i < n; i++) {
        if (dist[i] == INF)
            cout << "inf ";
        else
            cout << dist[i] << " ";
    }
}
