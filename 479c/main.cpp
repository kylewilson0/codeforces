#include <iostream>
#include <vector>
#include <algorithm>
#define LOCAL
using namespace std;
using pii = pair<int, int>;

vector<pii> d{};

void solve(const int n) {
    ranges::sort(d);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (d[i].second >= ans) {
            ans = d[i].second;
        } else ans = d[i].first;
    }
    cout << ans;
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1, n, a, b;
    //cin >> t;
    while (t--) {
        cin >> n;
        d.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            d[i] = {a, b};
        }
        solve(n);
    }
    return 0;
}
