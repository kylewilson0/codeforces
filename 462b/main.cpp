#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

#define int long long

signed main() {
    int n, k;
    array<int, 26> a{};
    char ch;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        a[ch - 'A']++;
    }
    sort(a.begin(), a.end(), greater<int>());
    int i = 0, ans = 0;
    while (k) {
        if (k >= a[i]) {
            ans += a[i] * a[i];
            k -= a[i];
        } else {
            ans += k * k;
            k = 0;
        }
        i++;
    }
    cout << ans;
    return 0;
}
