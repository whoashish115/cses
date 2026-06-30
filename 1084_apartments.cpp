/*
========================================
Problem  : Apartments
URL      : https://cses.fi/problemset/task/1084
Code     : https://github.com/whoashish115/cses
Author   : Ashish Kumar
Language : C++23
========================================
*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (b[j] < a[i] - k)
        {
            j++;
        }
        else if (b[j] > a[i] + k)
        {
            i++;
        }
        else
        {
            ans++;
            i++;
            j++;
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}