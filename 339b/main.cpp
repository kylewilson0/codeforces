#include <iostream>
using namespace std;

int main() {
    int n, m, t, last = 1;
    long long ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        if (t >= last) {
            ans += t - last;
        } else {
            ans += t + n - last;
        }
        last = t;
    }
    cout << ans << endl;
    return 0;
}
