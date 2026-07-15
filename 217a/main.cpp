#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>

#define fixed(x) fixed<<setprecision(x)
#define LOCAL

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

constexpr int INF = 0x3f3f3f3f;
constexpr ll LNF = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 1e9 + 7;
constexpr double EPS = 1e-8;
constexpr int N = 2e3 + 1;

array<pii, N> dot{};

struct DSU {
    vector<int> parent{};
    vector<ll> size{};
    int sz;

    DSU(const int n) : sz(n + 1) {
        parent.resize(sz);
        iota(parent.begin(), parent.end(), 0);
        size.assign(sz, 1);
    }

    int find(const int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (x > y) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
    }

    bool isConnected(const int x, const int y) {
        return find(x) == find(y);
    }
};

void solve() {
    int n, ans = 0;
    cin >> n;
    DSU dsu(N);
    for (int i = 0; i < n; i++) {
        cin >> dot[i].first >> dot[i].second;
        dsu.unite(dot[i].first, dot[i].second + 1000);
    }
    array<bool, N> flag{};
    for (int i = 0; i < n; i++) {
        int parent = dsu.find(dot[i].first);
        if (!flag[parent]) {
            flag[parent] = true;
            ++ans;
        }
    }
    cout << ans - 1;
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
