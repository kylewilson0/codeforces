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

vector<pii> ans{};

void solve() {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    for (int i = a; i <= x; ++i) {
        for (int j = b; j <= min(y, i - 1); ++j) {
            ans.emplace_back(i, j);
        }
    }
    cout << ans.size() << endl;
    for (auto [f,s]: ans) {
        cout << f << " " << s << endl;
    }
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
