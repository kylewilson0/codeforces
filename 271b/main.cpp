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

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

constexpr int INF = 0x3f3f3f3f;
constexpr ll LNF = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 1e9 + 7;
constexpr double EPS = 1e-8;
constexpr int N = 5e2 + 1;

#define LOCAL

struct EulerSieve {
    vector<int> prime{}, least_prime{};
    int sz;

    EulerSieve(int n) : sz(n + 1) {
        least_prime.reserve(sz);
        for (int i = 2; i < sz; i++) {
            if (!least_prime[i]) {
                prime.push_back(i);
                least_prime[i] = i;
            }
            for (auto &pri_j: prime) {
                if (i * pri_j >= sz) break;
                least_prime[i * pri_j] = pri_j;
                if (i % pri_j == 0) break;
            }
        }
    }
};

array<array<int, N>, N> a{};

void solve(const int n, const int m) {
    EulerSieve sieve(1e6);
    int ans = INF;
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (int j = 0; j < m; j++) {
            auto it = ranges::lower_bound(sieve.prime, a[i][j]);
            t += *it - a[i][j];
        }
        ans = min(ans, t);
    }
    for (int i = 0; i < m; i++) {
        int t = 0;
        for (int j = 0; j < n; j++) {
            auto it = ranges::lower_bound(sieve.prime, a[j][i]);
            t += *it - a[j][i];
        }
        ans = min(ans, t);
    }
    cout << ans;
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1, n, m;
    //cin >> t;
    cin >> n >> m;
    while (t--) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        solve(n, m);
    }
    return 0;
}
