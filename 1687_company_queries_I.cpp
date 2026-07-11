/*
========================================
Problem  : Company Queries I
URL      : https://cses.fi/problemset/task/1687
Code     : https://github.com/whoashish115/cses
Author   : Ashish Kumar
Language : C++23
========================================
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;

  int lim = 30;
  vector<vector<int>> dp(n + 1, vector<int>(lim, 0));
  for (int i = 2; i <= n; ++i) {
    cin >> dp[i][0];
  }
  for (int u = 1; u <= n; u++) {
    for (int i = 1; i < lim; i++) {
      dp[u][i] = dp[dp[u][i - 1]][i - 1];
    }
  }

  int x, k;
  while (q--) {
    cin >> x >> k;
    for (int i = lim - 1; i >= 0; --i) {
      if (k & (1 << i)) {
        x = dp[x][i];
      }
    }

    cout << (x == 0 ? -1 : x) << '\n';
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