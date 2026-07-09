#include<iostream>
#include<cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    long long n, k, e=1, p, t;
    cin >> n >> k;
    p = e << k;
    if (p > n) {
        cout << -1 << endl;
    }
    else {
        t = n / p;
        if (t % 2 == 0) {
            t -= 1;
        }
        if (t == 0) {
            cout << -1 << endl;
        } else {
            cout << t * p << endl;
        }
    }
}