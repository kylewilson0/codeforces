#include <iostream>
#include <array>

using namespace std;

constexpr int N = 1e5 + 1;
int n, c, d;

struct BIT {
    array<int, N> a{};

    static int lowbit(int x) {
        return x & -x;
    }

    void update(int x, int v) {
        for (int i = x; i < N; i += lowbit(i)) a[i] = max(a[i], v);
    }

    int find(int x) {
        int ans = 0;
        for (int i = x; i; i -= lowbit(i)) ans = max(ans, a[i]);
        return ans;
    }
};

void solve() {
    int beauty, price, ans = 0;
    char ch;
    BIT coin, diamond;
    for (int i = 0; i < n; i++) {
        cin >> beauty >> price >> ch;
        if (ch == 'C') {
            if (c < price) continue;
            if (c > price) {
                int t = coin.find(c - price);
                if (t) ans = max(ans, beauty + t);
            }
            coin.update(price, beauty);
        } else {
            if (d < price) continue;
            if (d > price) {
                int t = diamond.find(d - price);
                if (t) ans = max(ans, beauty + t);
            }
            diamond.update(price, beauty);
        }
    }
    int c1 = coin.find(c), d1 = diamond.find(d);
    if (c1 > 0 && d1 > 0) ans = max(ans, c1 + d1);
    cout << ans;
}

int main() {
    freopen("a.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        cin >> n >> c >> d;
        solve();
    }
    return 0;
}
