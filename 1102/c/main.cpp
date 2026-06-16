#include <iostream>
using namespace std;

constexpr int N = 6001;
long long t, n, a[N];

void solve() {
    for (int i = 0; i < n; i++) {
        long long l[N] = {0}, r[N] = {0};
        l[i] = a[i];
        for (int j = i + 1; j < i + n - 1; j++) {
            l[j] = max(l[j - 1], a[j]);
        }
        r[i + n - 2] = a[i + n - 1];
        for (int j = i + n - 3; j >= i; j--) {
            r[j] = max(r[j + 1], a[j + 1]);
        }
        long long tot = 0;
        for (int j = i; j < i + n - 1; j++) {
            tot += min(l[j], r[j]);
        }
        cout << tot << " ";
    }
    cout << endl;
}

void init() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
}

int main() {
    freopen("a.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        init();
        solve();
    }
    return 0;
}
