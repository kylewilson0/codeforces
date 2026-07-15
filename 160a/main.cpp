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
constexpr int N = 1e2 + 1;
array<int, N> a{};

void solve() {
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ranges::sort(a, greater());
    int i = 0, tot = 0;
    for (; i < n; i++) {
        tot += a[i];
        if (2 * tot > sum) break;
    }
    cout << i + 1;
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
