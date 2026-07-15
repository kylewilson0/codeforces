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

array<array<int, N>, N> f{};

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        f[i][1] = 1;
    }
    for (int len = 1; len < m; ++len) {
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; j += i) {
                f[j][len + 1] += f[i][len], f[j][len + 1] %= MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += f[i][m], ans %= MOD;
    }
    cout << ans;
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
