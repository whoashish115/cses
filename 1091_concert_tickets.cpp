/*
========================================
Problem  : Concert Tickets
URL      : https://cses.fi/problemset/task/1091
Code     : https://github.com/whoashish115/cses
Author   : Ashish Kumar
Language : C++23
========================================
*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    multiset<int> tickets;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tickets.insert(x);
    }

    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;

        auto it = tickets.upper_bound(t);

        if (it == tickets.begin())
        {
            cout << -1 << '\n';
        }
        else
        {
            --it;
            cout << *it << '\n';
            tickets.erase(it);
        }
    }
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