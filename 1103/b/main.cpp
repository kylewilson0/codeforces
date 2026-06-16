#include <iostream>
using namespace std;

constexpr int N = 2e5 + 1;

int main() {
    freopen("a.in", "r", stdin);
    int t, n, k;
    char ch;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int a[N] = {0};
        for (int i = 0; i < n; i++) {
            cin >> ch;
            a[i % k] += ch - '0';
        }
        bool ok = true;
        for (int i = 0; i < k; i++) {
            if (a[i] & 1) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
