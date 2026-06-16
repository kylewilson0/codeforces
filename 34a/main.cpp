#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, a[101], min_height = INT_MAX, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[n] = a[0];

    for (int i = 0; i < n; i++) {
        int t = abs(a[i] - a[i + 1]);
        if (t < min_height) {
            min_height = t;
            ans = i + 1;
        }
    }

    cout << ans << " " << (ans == n ? 1 : ans + 1) << endl;
    return 0;
}
