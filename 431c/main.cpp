#include <iostream>
#include <array>

using namespace std;
constexpr int MOD = 1e9 + 7;
constexpr int N = 1e2 + 1;

int n, k, d;
array<int, N> a{}, b{};

void solve() {
    a[0] = b[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            a[i] = (a[i] + a[i - j]) % MOD;
            if (j < d) b[i] = (b[i] + b[i - j]) % MOD;
        }
    }
    // cout << a[n] << " " << b[n] << endl;
    int ans = (a[n] - b[n] + MOD) % MOD;
    cout << ans;
}


int main() {
    freopen("a.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> k >> d;
    solve();
    return 0;
}
