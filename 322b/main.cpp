#include <iostream>
using namespace std;

int main() {
    int a[3], ans = 0;
    for (int &i: a) {
        cin >> i;
        ans += i / 3;
    }
    for (int i = 1; i <= 2; i++) {
        if (a[0] < i || a[1] < i || a[2] < i) continue;
        ans = max(ans, (a[0] - i) / 3 + (a[1] - i) / 3 + (a[2] - i) / 3 + i);
    }
    cout << ans;
    return 0;
}
