#include <iostream>
using namespace std;

int main() {
    int n, m, t, a[100001];
    long long ans_a = 0, ans_b = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        a[t] = i;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        ans_a += a[t];
        ans_b += n - a[t] + 1;
    }
    cout << ans_a << " " << ans_b << endl;
    return 0;
}
