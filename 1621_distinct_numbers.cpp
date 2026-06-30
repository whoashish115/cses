/*
========================================
Problem  : Distinct Numbers
URL      : https://cses.fi/problemset/task/1621
Code     : https://github.com/whoashish115/cses
Author   : Ashish Kumar
Language : C++23
========================================
*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int temp;
    set<int> s;
    while (n--)
    {
        cin >> temp;
        s.insert(temp);
    }
    cout << s.size() << '\n';
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