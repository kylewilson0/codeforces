#include <iostream>
#include <algorithm>
#include <array>

#define LOCAL

using namespace std;
using ll = long long;

constexpr int N = 5e2 + 1;

array<int, N> a{};

void solve() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.begin() + n);
    auto lo = lower_bound(a.begin(), a.begin() + n, x);
    auto up = upper_bound(a.begin(), a.begin() + n, x);
    int repeat = up - lo, l = lo - a.begin(), r = a.begin() + n - up;
    int ans = 0;
    if (*lo != x) {
        repeat++, ans++;
    }
    if (l < r) {
        if (l + repeat < r) ans += r - l - repeat;
    } else if (r < l) {
        if (r + repeat <= l) ans += l - r - repeat + 1;
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
