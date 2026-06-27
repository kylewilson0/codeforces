#include <iostream>
#include <array>
using namespace std;

#define  int long long
constexpr int N = 1e5 + 1;

array<int, N> a{};

signed main() {
    freopen("a.in", "r", stdin);
    int n, m, w, h, first = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> w >> h;
        if (i == 0) {
            first = a[w] + h;
            cout << a[w] << endl;
            continue;
        }
        first = max(first, a[w]);
        cout << first << endl;
        first += h;
    }
    return 0;
}
