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
constexpr int N = 1e3 + 1;

array<array<int, N>, N> d{};
array<int, N> r{}, c{};

void solve() {
    int n, m, k, a, b;
    char ch;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> d[i][j];
    }
    iota(r.begin(), r.end(), 0);
    iota(c.begin(), c.end(), 0);
    for (int i = 0; i < k; i++) {
        cin >> ch >> a >> b;
        a--, b--;
        if (ch == 'r') {
            int ta = r[a], tb = r[b];
            r[a] = tb, r[b] = ta;
        } else if (ch == 'c') {
            int ta = c[a], tb = c[b];
            c[a] = tb, c[b] = ta;
        } else {
            cout << d[r[a]][c[b]] << endl;
        }
    }
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
