#include <iostream>
#include <algorithm>
using namespace std;
#define N 51

int main() {
    int n, m, a[N], ans = INT_MAX;
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i];
    sort(a, a + m);
    for (int i = 0; i <= m - n; i++) ans = min(ans, a[i + n - 1] - a[i]);
    cout << ans << endl;
    return 0;
}
