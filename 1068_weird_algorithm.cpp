/*
========================================
Problem  : Weird Algorithm
URL      : https://cses.fi/problemset/task/1068
Code     : https://github.com/whoashish115/cses
Author   : Ashish Kumar
Language : C++23
========================================
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long n;
  cin >> n;
  while (true) {
    cout << n << " ";
    if (n == 1)
      break;

    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = 3 * n + 1;
    }
  }
}

  int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
      solve();
    }

    return 0;
  }