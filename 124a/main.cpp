#include <iostream>
using namespace std;

int main() {
    int n, a, b, ans = 0;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        if (i >= a && n - i - 1 <= b) ans++;
    }
    cout << ans;
    return 0;
}
