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
constexpr int N = 1e5 + 1;

#define LOCAL

array<int, N> a{};

void solve(const int n, const int t) {
    int i = 0, j = 0, sum = 0, ans = 0;
    while (j < n) {
        while (j < n && sum + a[j] <= t) {
            sum += a[j];
            ++j;
        }
        ans = max(ans, j - i);
        sum -= a[i];
        i++;
    }
    cout << ans << endl;
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> a[i];
    solve(n, t);
    return 0;
}
