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

void print(int a, int b) {
    for (int i = 0; i < a; i++) cout << 4;
    for (int i = 0; i < b; i++) cout << 7;
}

bool solve() {
    int n, a = 0, b = 0, r;
    cin >> n;
    b = n / 7;
    r = n % 7;
    a = r / 4;
    r = r % 4;
    if (r == 0) {
        print(a, b);
        return true;
    }
    switch (r) {
        case 1:
            if (b >= 1) {
                b--, a += 2;
            } else return false;
            break;
        case 2:
            if (b >= 2) {
                b -= 2, a += 4;
            } else return false;
            break;
        default:
            if (b >= 3) {
                b -= 3, a += 6;
            } else return false;
    }
    print(a, b);
    return true;
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        bool ans = solve();
        if (!ans) cout << -1;
    }
    return 0;
}
