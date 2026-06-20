#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n, ans = 0;
    cin >> n;
    int m = static_cast<int>(sqrt(n * 1.0));
    for (int i = 1; i <= m; i += 2) {
        for (int j = 2; j <= m; j += 2) {
            if (gcd(i, j) != 1) continue;
            int c = i * i + j * j;
            if (c <= n) {
                ans += n / c;
            }
        }
    }
    cout << ans;
    return 0;
}
