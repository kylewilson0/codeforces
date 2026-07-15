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

ll solve() {
    ll n, ans = 1;
    cin >> n;
    if (n <= 3) {
        for (int i = 1; i <= n; i++) ans *= i;
        return ans;
    }
    if (n & 1) {
        ans = n * (n - 1) * (n - 2);
    } else {
        if (gcd(n, n - 3) == 1) {
            ans = n * (n - 1) * (n - 3);
        } else {
            ans = (n - 1) * (n - 2) * (n - 3);
        }
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        cout << solve();
    }
    return 0;
}
