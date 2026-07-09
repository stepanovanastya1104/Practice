#include<iostream>
#include<cmath>
#include<set>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

void dfs(vector<vector<int>> &gr, vector<int> &colors, vector<int> &prev, int u, int v){
    colors[u] = 1;
    if (u == v)
        return;
    for (int to : gr[u]) {
        if (colors[to] == 0) {
            prev[to] = u;
            dfs(gr, colors, prev, to, v);
            if (colors[v] == 1)
                return;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, i, j, k, a, b, maxx=20000000, l=0, r, mid, x, y, z, m, s3=0, d, t, ans, p, cnt1, cnt2, u, v, U, V;
    cin >> n >> m >> U >> V;
    U--;
    V--;
    vector<vector<int>> gr(n);
    for (i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    vector<int> colors(n, 0);
    vector<int> prev(n, -1);
    dfs(gr, colors, prev, U, V);
    if (colors[V] == 0) {
        cout << -1;
        return 0;
    }
    vector<int> path;
    for (int cur = V; cur != -1; cur = prev[cur])
        path.push_back(cur + 1);

    for (i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}