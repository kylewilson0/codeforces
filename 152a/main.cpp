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

array<array<int, N>, N> a{};

array<int, N> b{};

void solve() {
    int n, m, ans = 0;
    char ch;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ch;
            a[i][j] = ch - '0';
            b[j] = max(b[j], a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == b[j]) {
                flag = true;
                break;
            }
        }
        if (flag) ans++;
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
