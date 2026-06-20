#include <iostream>
#include <array>

using namespace std;
const int N = 4e3 + 1;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    array<int, N> f = {};
    f[a] = f[b] = f[c] = 1;
    for (int i = 1; i <= n; ++i) {
        if (i > a && f[i - a] > 0) {
            f[i] = max(f[i], f[i - a] + 1);
        }
        if (i > b && f[i - b] > 0) {
            f[i] = max(f[i], f[i - b] + 1);
        }
        if (i > c && f[i - c] > 0) {
            f[i] = max(f[i], f[i - c] + 1);
        }
    }
    cout << f[n];
    return 0;
}
