#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

constexpr int N = 1e5 + 1;
array<int, N> a{};

int main() {
    freopen("a.in", "r", stdin);
    int n, m, d;
    cin >> n >> m >> d;
    n *= m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.begin() + n);
    int ans = 0, mid = n / 2;
    for (int i = 0; i < n; i++) {
        int t = abs(a[i] - a[mid]);
        if (t % d) {
            cout << -1;
            return 0;
        }
        ans += t / d;
    }
    cout << ans;
    return 0;
}
