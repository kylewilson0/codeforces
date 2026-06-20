#include <iostream>
#include <array>
using namespace std;
constexpr int N = 1e5 + 1;

int main() {
    freopen("a.in", "r", stdin);
    int n;
    array<int, N> a{};
    cin >> n;
    a[0] = 0;
    a[n + 1] = 1e9 + 1;
    for (int i = 0; i < n; ++i) cin >> a[i + 1];
    int i = 0, l = 0, r = 0;
    bool flag = false;
    while (i <= n) {
        if (a[i + 1] > a[i]) {
            i++;
            continue;
        }
        if (flag) {
            cout << "no";
            return 0;
        }
        flag = true;
        int j = i;
        while (a[j + 1] < a[j]) j++;
        l = i, r = j;
        if (a[r] < a[l - 1] || a[l] > a[r + 1]) {
            cout << "no";
            return 0;
        }
        i = j + 1;
    }
    if (!flag) cout << "yes\n1 1";
    else cout << "yes\n" << l << " " << r;
    return 0;
}
