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

bool solve() {
    string a, b;
    int ca = 0, cb = 0;
    cin >> a >> b;
    if (a.size() != b.size()) return false;
    for (auto &c: a) {
        if (c == '1') {
            ca = 1;
            break;
        }
    }
    for (auto &c: b) {
        if (c == '1') {
            cb = 1;
            break;
        }
    }
    return !(ca ^ cb);
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << (solve() ? "YES" : "NO");
    return 0;
}
