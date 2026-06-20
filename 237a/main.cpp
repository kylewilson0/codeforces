#include <iostream>
using namespace std;

int main() {
    int n, a, b, la = 0, lb = 0, ans = 0, cur = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (la == a && lb == b) {
            cur++;
        } else {
            cur = 1;
        }
        la = a, lb = b;
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}
