#include <iostream>
#include <algorithm>
#include <array>

#define LOCAL

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
constexpr int N = 1e5 + 1;

array<pll, N> d{};

void solve() {
    int n, r, a, b;
    ll m, ans = 0;
    cin >> n >> r >> m;
    m = m * n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        d[i] = {b, a};
        m -= a;
    }
    sort(d.begin(), d.begin() + n);
    int i = 0;
    while (i < n) {
        if (m <= 0) break;
        ll t = min(m, r - d[i].second);
        ans += d[i].first * t;
        m -= t;
        i++;
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
