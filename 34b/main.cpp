#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m, t, a[101], cnt = 0, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t < 0) a[cnt++] = t;
    }
    sort(a, a + cnt);
    for (int i = 0; i < min(cnt, m); i++) ans += a[i];
    cout << -ans << endl;
    return 0;
}
