#include <iostream>
#include <array>

#define LOCAL

using namespace std;
using ll = long long;

constexpr int N = 1e5 + 1;

array<ll, N> a{}, f{};

void solve() {
    f[1] = a[1];
    for (int i = 2; i < N; i++) {
        f[i] = max(f[i - 1], f[i - 2] + a[i]);
    }
    cout << f[N - 1];
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v;
        a[v] += v;
    }
    solve();
    return 0;
}
