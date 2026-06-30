/*
========================================
Problem  : Traffic Lights
URL      : https://cses.fi/problemset/task/1163
Code     : https://github.com/whoashish115/cses
Author   : Ashish Kumar
Language : C++23
========================================
*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x, n;
    cin >> x >> n;

    set<int> lights;
    multiset<int> seg;

    lights.insert(0);
    lights.insert(x);
    seg.insert(x);

    while (n--)
    {
        int p;
        cin >> p;

        auto it = lights.upper_bound(p);
        int r = *it;
        int l = *prev(it);

        seg.erase(seg.find(r - l));
        seg.insert(p - l);
        seg.insert(r - p);

        lights.insert(p);

        cout << *seg.rbegin() << " ";
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