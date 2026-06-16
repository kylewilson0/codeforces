#include <iostream>
#include <algorithm>
using namespace std;
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)

int main() {
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, a[6];
    cin >> t;
    while (t--) {
        cin >> n;
        _rep(i, 0, n-1) cin >> a[i];
        int *t1 = max_element(a, a + n);
        int *t2 = min_element(a, a + n);
        cout << *t1 - *t2 + 1 << endl;
    }
    return 0;
}
