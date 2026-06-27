#include <iostream>
#include <array>
using namespace std;

array divisor = {2, 3, 5};
array<array<int, 3>, 2> cnt{};

void solve(int &x, int index) {
    while (x) {
        bool flag = false;
        for (int i = 0; i < 3; i++) {
            if (x % divisor[i] == 0) {
                cnt[index][i]++, x /= divisor[i];
                flag = true;
            }
        }
        if (!flag) break;
    }
}

int main() {
    freopen("a.in", "r", stdin);
    int a, b;
    cin >> a >> b;
    solve(a, 0);
    solve(b, 1);
    if (a != b) {
        cout << -1;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        ans += abs(cnt[0][i] - cnt[1][i]);
    }
    cout << ans;
    return 0;
}
