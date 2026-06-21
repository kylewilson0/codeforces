#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

struct DSU {
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (px < py) parent[py] = px;
        else parent[px] = py;
    }
};

int main() {
    freopen("a.in", "r", stdin);
    int n, m, k, t, zero = 0;
    cin >> n >> m;
    DSU dsu(n + m);
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (k == 0) {
            zero++;
            continue;
        }
        for (int j = 0; j < k; j++) {
            cin >> t;
            dsu.unite(i, t + n - 1);
        }
    }
    if (zero == n) {
        cout << n;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dsu.find(i) == i) ans++;
    }
    cout << ans - 1;
    return 0;
}
