/*
========================================
Problem  : Counting Divisors
URL      : https://cses.fi/problemset/task/1713
Code     : https://github.com/whoashish115/cses
Author   : Ashish Kumar
Language : C++23
========================================
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int count = 0;
    for (int d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            count++;
            if (d != n / d) {
                count++;
            }
        }
    }
    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
