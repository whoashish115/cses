/*
========================================
Problem  : Permutations
URL      : https://cses.fi/problemset/task/1070
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
  if (n ==2 || n==3){
    cout << "NO SOLUTION\n";
    return;
  }
  if (n == 4) {
    cout << "3 1 4 2\n";
    return;
  }
  for (int i = 1; i <= n; i += 2) {
    cout << i << ' ';
  }
  for (int i = 2; i <= n; i += 2) {
    cout << i << ' ';
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