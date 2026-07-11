/*
========================================
Problem  : Planet Queries I
URL      : https://cses.fi/problemset/task/1750
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

  int lim = 31;
  vector<vector<int>> dp(n + 1, vector<int>(lim, 0));
  for (int i = 1; i <= n; ++i) {
    cin >> dp[i][0];
  }
  for (int i = 1; i < lim; i++) {
    for (int u = 1; u <= n; u++) {
      dp[u][i] = dp[dp[u][i - 1]][i - 1];
    }
  }

  int x;
  long long k;
  while (q--) {
    cin >> x >> k;
    for (int i = lim - 1; i >= 0; --i) {
      if (k & (1LL << i)) {
        x = dp[x][i];
      }
    }

    cout << x << '\n';
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