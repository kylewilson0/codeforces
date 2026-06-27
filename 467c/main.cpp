#include <iostream>
#include <array>
using namespace std;

#define int long long

constexpr int N = 5e3 + 1;

array<int, N> a{};
array<array<int, N>, N> f{};

signed main() {
    freopen("a.in", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            if (j >= m) {
                int v = a[j] - a[j - m];
                f[j][i] = max(f[j - 1][i], f[j - m][i - 1] + v);
            }
        }
    }
    cout << f[n][k];
    return 0;
}
