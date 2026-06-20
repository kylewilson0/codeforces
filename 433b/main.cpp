#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

constexpr int N = 1e5 + 1;

int main() {
    freopen("a.in", "r", stdin);
    array<long long, N> a = {}, b = {};
    int n, m, t, l, r;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
        a[i] += a[i - 1];
    }
    sort(b.begin() + 1, b.begin() + n + 1);
    for (int i = 1; i <= n; ++i) b[i] += b[i - 1];
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> t >> l >> r;
        if (t == 1) cout << a[r] - a[l - 1] << endl;
        else cout << b[r] - b[l - 1] << endl;
    }
    return 0;
}
