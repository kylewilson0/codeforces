#include <iostream>
using namespace std;

int main() {
    int n, k, f, t, ans = INT_MIN;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> f >> t;
        if (t <= k) {
            ans = max(ans, f);
        } else {
            ans = max(ans, f - t + k);
        }
    }
    cout << ans;
    return 0;
}
