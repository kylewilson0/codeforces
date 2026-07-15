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
constexpr int N = 2e5 + 1;

array<int, N> a{};
int n, m;

array<int, 2> solve(int first) {
    a[0] = first;
    int i = 1, cnt[] = {n, m};
    cnt[first]--;
    while (i < n + m) {
        if (i & 1) {
            int t = 1 - a[i - 1];
            if (cnt[t]) a[i] = t, cnt[t]--;
            else a[i] = 1 - t, cnt[1 - t]--;
        } else {
            int t = a[i - 1];
            if (cnt[t]) a[i] = t, cnt[t]--;
            else a[i] = 1 - t, cnt[1 - t]--;
        }
        i++;
    }
    int ans_a = 0, ans_b = 0;
    for (int i = 0; i < n + m - 1; i++) {
        if (a[i] == a[i + 1]) ans_a++;
        else ans_b++;
    }
    return {ans_a, ans_b};
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    array ans1 = solve(0);
    array ans2 = solve(1);
    if (ans1[0] > ans2[0]) {
        cout << ans1[0] << " " << ans1[1];
    } else {
        cout << ans2[0] << " " << ans2[1];
    }
    return 0;
}
