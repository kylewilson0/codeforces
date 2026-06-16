#include <iostream>
#include <vector>
using namespace std;

#define LOCAL
constexpr int N = 6e3 + 1;

int a[N], n;

int solve() {
    vector con(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        vector<bool> flag(n);
        int l = a[i], r = a[i];
        for (int j = i; j < n; j++) {
            if (flag[a[j]]) break;
            flag[a[j]] = true;
            l = min(l, a[j]), r = max(r, a[j]);
            if (r - l == j - i) con[l][r] = true;
        }
    }
    for (int i = n; i > 0; i--) {
        for (int j = 0; j + 2 * i - 1 < n; j++) {
            if (con[j][j + i - 1] && con[j + i][j + 2 * i - 1]) {
                return i;
            }
        }
    }
    return 0;
}

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]), a[i]--;
        printf("%d\n", solve());
    }
    return 0;
}
