#include <iostream>
#include <set>
#include <queue>
#define LOCAL
using namespace std;
using pii = pair<int, int>;
constexpr int N = 1e5 + 1;
int n, a[N];

int solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    priority_queue<pii> q;
    for (int i = 1; i < n; i++) q.emplace(n - i, i);
    int lose = 0;
    set<pii> seg, len;
    for (int i = n - 1; i >= 1; i--) {
        while (!q.empty() && q.top().first >= i) {
            int v = q.top().second;
            int l = v, r = v;
            q.pop();
            auto it = seg.upper_bound({v, v});
            if (it != seg.begin()) {
                auto pre = prev(it);
                if (pre->second + 1 == v) {
                    l = pre->first;
                    int s = pre->second - pre->first + 1, t = pre->first;
                    len.erase({s, t});
                    seg.erase(pre);
                }
            }
            if (it != seg.end()) {
                if (v + 1 == it->first) {
                    r = it->second;
                    int s = it->second - it->first + 1, t = it->first;
                    len.erase({s, t});
                    seg.erase(it);
                }
            }
            seg.emplace(l, r);
            len.emplace(r - l + 1, l);
        }
        while (len.rbegin()->first > a[i]) {
            auto [d,l] = *len.rbegin();
            int r = l + d - 1;
            for (int j = l; j <= r - a[i]; ++j) {
                int k = i - j - 1;
                if (k > 0) q.emplace(k, j);
                lose |= i == 1 && j == 1;
            }
            seg.erase({l, r});
            len.erase({d, l});
            seg.emplace(r - a[i] + 1, r);
            len.emplace(a[i], r - a[i] + 1);
        }
    }
    cout << lose + 1 << endl;
    return 0;
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
