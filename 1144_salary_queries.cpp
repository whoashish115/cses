/*
========================================
Problem  : Salary Queries
URL      : https://cses.fi/problemset/task/1144
Code     : https://github.com/whoashish115/cses
Author   : Ashish Kumar
Language : C++23
========================================
*/

/*
Coordinate compression + Fenwick Tree
*/


#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void update(int idx, int delta) {
        while (idx <= n) {
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<tuple<char, int, int>> queries;
    vector<int> values;

    for (int x : p) values.push_back(x);

    for (int i = 0; i < q; i++) {
        char type;
        cin >> type;
        if (type == '!') {
            int k, x;
            cin >> k >> x;
            queries.emplace_back(type, k - 1, x);
            values.push_back(x);
        } else {
            int a, b;
            cin >> a >> b;
            queries.emplace_back(type, a, b);
            values.push_back(a);
            values.push_back(b);
        }
    }

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    auto getId = [&](int x) {
        return int(lower_bound(values.begin(), values.end(), x) - values.begin()) + 1;
    };

    Fenwick fw(values.size());

    for (int i = 0; i < n; i++) {
        fw.update(getId(p[i]), 1);
    }

    for (auto &[type, x, y] : queries) {
        if (type == '!') {
            fw.update(getId(p[x]), -1);
            p[x] = y;
            fw.update(getId(p[x]), +1);
        } else {
            int left = getId(x);
            int right = getId(y);
            cout << fw.rangeQuery(left, right) << "\n";
        }
    }

    return 0;
}
