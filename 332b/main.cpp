#include <iostream>
#include <array>
#include <vector>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 1;

int n, k;
array<ll, N> a{};
array<array<ll, 3>, N> f{};
array<array<int, 3>, N> trace{};

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n; j++) {
            if (j >= k) {
                ll t = f[j - k][i - 1] + a[j] - a[j - k];
                if (t > f[j - 1][i]) {
                    f[j][i] = t;
                    trace[j][i] = j - k + 1;
                } else {
                    f[j][i] = f[j - 1][i];
                    trace[j][i] = trace[j - 1][i];
                }
            }
        }
    }
    int i = n, j = 2;
    vector<int> ans{};
    while (j) {
        ans.push_back(trace[i][j]);
        i = trace[i][j] - 1;
        j--;
    }
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
}

int main() {
    freopen("a.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
