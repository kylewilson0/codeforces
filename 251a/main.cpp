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
constexpr int N = 1e5 + 1;

array<int, N> a{};

void solve() {
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int i = 3, j = 1;
    ll ans = 0;
    while (i <= n) {
        while (a[i] - a[j] > d) ++j;
        if (i - j >= 2) ans += (i - j) * (i - j - 1) / 2;
        ++i;
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
