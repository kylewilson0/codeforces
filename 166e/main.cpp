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
constexpr int N = 1e7 + 1;

array<array<ll, 4>, 2> f;

void solve(const int n) {
    int t = 0;
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        t = 1 - t;
        for (int j = 0; j < 4; ++j) {
            f[t][j] = (f[1 - t][(j + 1) % 4] + f[1 - t][(j + 2) % 4] + f[1 - t][(j + 3) % 4]) % MOD;
        }
    }
    cout << f[t][0];
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1, n;
    //cin >> t;
    cin >> n;
    solve(n);
    return 0;
}
