#include <iostream>
using namespace std;

int main() {
    int n, left = 0, right = 0, l, r, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        left += l;
        right += r;
    }
    ans = min(n - left, left) + min(n - right, right);
    cout << ans << endl;
    return 0;
}
