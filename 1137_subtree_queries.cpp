/*
========================================
Problem  : Subtree Queries
URL      : https://cses.fi/problemset/task/1137
Code     : https://github.com/whoashish115/cses
Author   : Ashish Kumar
Language : C++23
========================================
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, q;
vector<ll> value;
vector<ll> bit;
vector<ll> euler;
vector<vector<int>> graph;
vector<int> inTime, outTime;
int timer = 0;

void update(int index, ll delta) {
    while (index <= n) {
        bit[index] += delta;
        index += index & -index;
    }
}

ll query(int index) {
    ll sum = 0;
    while (index > 0) {
        sum += bit[index];
        index -= index & -index;
    }
    return sum;
}

void dfs(int node, int parent) {
    inTime[node] = ++timer;
    euler[timer] = value[node];
    for (int child : graph[node]) {
        if (child != parent)
            dfs(child, node);
    }
    outTime[node] = timer;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    value.assign(n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> value[i];

    graph.assign(n + 1, {});

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    inTime.assign(n + 1, 0);
    outTime.assign(n + 1, 0);
    euler.assign(n + 1, 0);
    dfs(1, 0);
    bit.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        update(i, euler[i]);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int node;
            ll newValue;
            cin >> node >> newValue;
            ll delta = newValue - value[node];
            value[node] = newValue;
            update(inTime[node], delta);
        }
        else {
            int node;
            cin >> node;
            cout << query(outTime[node]) - query(inTime[node] - 1) << '\n';
        }
    }
    return 0;
}