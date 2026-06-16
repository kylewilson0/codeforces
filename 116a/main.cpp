#include <iostream>
using namespace std;

int main() {
    int n, a, b, ans = 0, cur = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cur = cur - a + b;
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}
