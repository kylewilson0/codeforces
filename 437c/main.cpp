#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

constexpr int N = 1e3 + 1;

struct Edge {
    int to, next;
};

array<int, N> head{};
array<Edge, 2 * N> next_edge{};
array<int, N> value{};
array<pair<int, int>, N> a{};
int edge_idx;

void add_edge(int from, int to) {
    next_edge[edge_idx] = {to, head[from]};
    head[from] = edge_idx++;
}

void init_graph(int m) {
    ranges::fill(head, -1);
    edge_idx = 0;
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        if (value[u] < value[v]) add_edge(v, u);
        else if (value[v] < value[u])add_edge(u, v);
        else {
            if (u < v) add_edge(v, u);
            else add_edge(u, v);
        }
    }
}

void solve(int n, int m) {
    init_graph(m);
    auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    };
    sort(a.begin(), a.begin() + n, cmp);
    int ans = 0;
    array<bool, N> b{};
    for (int i = 0; i < n; i++) {
        int u = a[i].second;
        b[u] = true;
        for (int i = head[u]; ~i; i = next_edge[i].next) {
            int to = next_edge[i].to;
            if (!b[to]) ans += value[to];
        }
    }
    cout << ans;
}

void solve2(int m) {
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        ans += min(value[u], value[v]);
    }
    cout << ans;
}

int main() {
    freopen("a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> value[i];
        a[i] = {value[i], i};
    }
    // solve(n, m);
    solve2(m);
    return 0;
}
