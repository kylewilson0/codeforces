#include <iostream>
using namespace std;

int main() {
    int n, l = INT_MAX, r = INT_MIN, a, b, ans = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a < l) {
            ans = -1;
            l = a;
        }
        if (b > r) {
            ans = -1;
            r = b;
        }
        if (a <= l && b >= r) {
            ans = i + 1;
        }
    }
    cout << ans;
    return 0;
}
