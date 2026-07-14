/*
========================================
Problem  : Sum Of Divisors
URL      : https://cses.fi/problemset/task/1082
Code     : https://github.com/whoashish115/cses
Author   : Ashish Kumar
Language : C++23
========================================
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1000000007;
const ll INV2 = 500000004;

ll pref(ll x) {
    x %= MOD;
    return x * ((x + 1) % MOD) % MOD * INV2 % MOD;
}

void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll l = 1; l <= n; ) {
        ll q = n / l;
        ll r = n / q;
        ll sum = (pref(r) - pref(l - 1) + MOD) % MOD;
        ans = (ans + sum * (q % MOD)) % MOD;

        l = r + 1;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}