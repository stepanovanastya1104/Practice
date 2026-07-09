#include<iostream>
#include<cmath>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    long long n, a, b, x, m1=0, m2=0, mid;
    cin >> n;
    priority_queue<long long> mi;
    priority_queue<long long, vector<long long>, greater<long long>> ma;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (mi.empty() || x <= mi.top())
            mi.push(x);
        else
            ma.push(x);
        if (mi.size() < ma.size()) {
            mi.push(ma.top());
            ma.pop();
        } else if (mi.size() > ma.size() + 1) {
            ma.push(mi.top());
            mi.pop();
        }
        cout << mi.top() << "\n";
    }
}