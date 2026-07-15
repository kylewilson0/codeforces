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
constexpr int N = 31;

array<int, N> ans{};
array<bool, N * N> seg{};

void solve(const int n, const int k) {
    int a;
    for (int i = 1; i <= k; ++i) {
        cin >> a;
        seg[a] = true;
        ans[i] = a;
    }
    int i = 1, j = 1;
    while (i <= k) {
        cout << ans[i] << " ";
        for (int l = 1; l < n; ++l) {
            while (seg[j]) j++;
            seg[j] = true;
            cout << j << " ";
        }
        cout << endl;
        i++, j++;
    }
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1, n, k;
    //cin >> t;
    cin >> n >> k;
    while (t--) {
        solve(n, k);
    }
    return 0;
}
