/*
========================================
Problem  : Company Queries II
URL      : https://cses.fi/problemset/task/1688
Code     : https://github.com/whoashish115/cses
Author   : Ashish Kumar
Language : C++23
========================================
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<vector<int>> &dp,
         vector<int> &level, int lim) {

  for (int i = 1; i < lim; i++) {
    dp[u][i] = dp[dp[u][i - 1]][i - 1];
  }

  for (int v : adj[u]) {
    level[v] = level[u] + 1;
    dfs(v, adj, dp, level, lim);
  }
}

void solve() {
  int n, q;
  cin >> n >> q;

  int lim = 20;
  vector<vector<int>> dp(n + 1, vector<int>(lim, 0));
  vector<vector<int>> adj(n + 1);
  vector<int> level(n + 1, 0);

  for (int i = 2; i <= n; i++) {
    cin >> dp[i][0];
    adj[dp[i][0]].push_back(i);
  }

  dfs(1, adj, dp, level, lim);
  int u, v;
  while (q--) {
    cin >> u >> v;

    if (level[u] < level[v])
      swap(u, v);

    int diff = level[u] - level[v];

    for (int i = 0; i < lim; i++) {
      if ((1 << i) & diff)
        u = dp[u][i];
    }
    if (u == v) {
      cout << u << endl;
      continue;
    }
    for (int i = lim - 1; i >= 0; i--) {
      if (dp[u][i] != dp[v][i]) {
        u = dp[u][i];
        v = dp[v][i];
      }
    }
    cout << dp[u][0] << endl;
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