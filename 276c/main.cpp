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

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

constexpr int INF = 0x3f3f3f3f;
constexpr ll LNF = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 1e9 + 7;
constexpr double EPS = 1e-8;
constexpr int N = 1e5 + 1;

#define LOCAL

struct BIT_RANGE {
    vector<ll> bit1{}, bit2{};
    int size;

    BIT_RANGE(const int n) : size(n + 1) {
        bit1.resize(size);
        bit2.resize(size);
    }

    void build(const vector<ll> &a) {
        for (int i = 0; i < a.size(); i++) {
            int j = i + 1;
            bit1[j] += a[i];
            bit2[j] += a[i] * j;
            int parent = j + lowbit(j);
            if (parent < size) bit1[parent] += bit1[j], bit2[parent] += bit2[j];
        }
    }

    static int lowbit(int i) {
        return i & -i;
    }

    void update(vector<ll> &bit, int i, const ll x) const {
        for (; i < size; i += lowbit(i)) bit[i] += x;
    }

    static ll query(const vector<ll> &bit, int i) {
        ll ret = 0;
        for (; i; i -= lowbit(i)) ret += bit[i];
        return ret;
    }

    void updatePoint(const int i, const ll x) {
        update(bit1, i, x);
        update(bit2, i, x * i);
    }

    void updateRange(const int l, const int r, const ll x) {
        update(bit1, l, x), update(bit1, r + 1, -x);
        update(bit2, l, x * l), update(bit2, r + 1, -x * (r + 1));
    }

    ll queryPrefix(const int i) const {
        return query(bit1, i) * (i + 1) - query(bit2, i);
    }

    ll queryRange(const int l, const int r) const {
        return queryPrefix(r) - queryPrefix(l - 1);
    }
};

void solve() {
    int n, q, l, r;
    cin >> n >> q;

    BIT_RANGE bit(n);
    vector<ll> a(n), cnt(n, 0);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        bit.updateRange(l, r, 1);
    }
    for (int i = 1; i <= n; ++i) cnt[i - 1] = bit.queryRange(i, i);
    ranges::sort(cnt, greater());
    ranges::sort(a, greater());
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i] * cnt[i];
    }
    cout << ans;
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
