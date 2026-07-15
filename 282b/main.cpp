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

void solve(const int n) {
    int fa = 0, fb = 0, a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (fa + a - fb <= 500) {
            fa += a;
            cout << 'A';
        } else {
            fb += b;
            cout << 'G';
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1, n;
    //cin >> t;
    cin >> n;
    while (t--) {
        solve(n);
    }
    return 0;
}
