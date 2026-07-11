/*
========================================
Problem  : Distance Queries
URL      : https://cses.fi/problemset/task/1135
Code     : https://github.com/whoashish115/cses
Author   : Ashish Kumar
Language : C++23
========================================
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int p, vector<vector<int>> &adj, vector<vector<int>> &dp,
         vector<int> &level, int lim) {
  dp[u][0] = p;

  for (int i = 1; i < lim; i++) {
    dp[u][i] = dp[dp[u][i - 1]][i - 1];
  }

  for (int v : adj[u]) {
    if (v == p)
      continue;
    level[v] = level[u] + 1;
    dfs(v, u, adj, dp, level, lim);
  }
}

void solve() {
  int n, q;
  cin >> n >> q;

  int lim = 20;
  vector<vector<int>> dp(n + 1, vector<int>(lim, 0));
  vector<vector<int>> adj(n + 1);
  vector<int> level(n + 1, 0);

  int a, b;
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1, 0, adj, dp, level, lim);
  int u, v;
  while (q--) {
    cin >> u >> v;
    int uu = u, vv = v;

    if (level[u] < level[v])
      swap(u, v);

    int diff = level[u] - level[v];
    for (int i = 0; i < lim; i++) {
      if (diff & (1 << i))
        u = dp[u][i];
    }

    if (u == v) {
      cout << level[uu] + level[vv] - 2 * level[u] << '\n';
      continue;
    }
    for (int i = lim - 1; i >= 0; i--) {
      if (dp[u][i] != dp[v][i]) {
        u = dp[u][i];
        v = dp[v][i];
      }
    }
    int lca = dp[u][0];
    cout << level[uu] + level[vv] - 2 * level[lca] << '\n';
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