#include <iostream>
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rp(i, a, b) for (int i = (a); i >= (b); --i)
#define LOCAL

using namespace std;
using ll = long long;

constexpr int N = 2e3 + 1;

ll a[N][N], s1[N << 1], s2[N << 1], s[2]{-1, -1};
int x[2], y[2];

void solve() {
    int n;
    cin >> n;
    fr(i, 1, n) {
        fr(j, 1, n) {
            cin >> a[i][j];
            s1[i + j] += a[i][j];
            s2[i - j + n] += a[i][j];
        }
    }
    fr(i, 1, n) {
        fr(j, 1, n) {
            ll c = s1[i + j] + s2[i - j + n] - a[i][j];
            int t = i + j & 1;
            if (c > s[t]) x[t] = i, y[t] = j, s[t] = c;
        }
    }
    printf("%lld\n%d %d %d %d", s[0] + s[1], x[0], y[0], x[1], y[1]);
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
